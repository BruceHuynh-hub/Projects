#include "interconnect.h"


//void interconnect::thread_1() {
//    while (true) {
//        //try to lock the mutex
//            if (bus.trylock() == -1) {
//                //failed, wait to lock
//                bus.lock();
//                std::cout << sc_time_stamp() << ": thread_1 obtained resource by lock()" << std::endl;
//               // succeeded
//            }
//            else {
//                std::cout << sc_time_stamp() << ": thread_1 obtained resource by trylock()" << std::endl;
//            }
//       // occupy mutex for 1 s
//            wait(1, SC_SEC);
//       // unlock mutex
//            bus.unlock();
//       // std::cout << sc_time_stamp() << ": unlocked by thread_1" << std::endl;
//       // give time for the other process to lock the mutex
//            wait(SC_ZERO_TIME);
//    }
//}
//
//
//void interconnect::thread_2() {
//    while (true) {
//        //try to lock the mutex
//            if (bus.trylock() == -1) {
//                //failed, wait to lock
//                bus.lock();
//                std::cout << sc_time_stamp() << ": thread_2 obtained resource by lock()" << std::endl;
//                //succeeded
//            }
//            else {
//                std::cout << sc_time_stamp() << ": thread_2 obtained resource by trylock()" << std::endl;
//            }
//        //occupy mutex for 1 s
//            wait(1, SC_SEC);
//        //unlock mutex
//            bus.unlock();
//        std::cout << sc_time_stamp() << ": unlocked by thread_2" << std::endl;
//        //give time for the other process to lock the mutex
//            wait(SC_ZERO_TIME);
//    }
//}


tlm::tlm_sync_enum interconnect::nb_transport_fw
(int SocketID, tlm::tlm_generic_payload& receivedTrans,
	tlm::tlm_phase& phase, sc_time& delay) {



	tlm::tlm_command cmd = receivedTrans.get_command();
	uint64           adr = receivedTrans.get_address();
	unsigned char* ptr = receivedTrans.get_data_ptr();
	unsigned int     len = receivedTrans.get_data_length();
	unsigned char* byt = receivedTrans.get_byte_enable_ptr();
	unsigned int     wid = receivedTrans.get_streaming_width();
	//if (bus.trylock() == -1) {

	if (byt != 0) {
		receivedTrans.set_response_status(tlm::TLM_BYTE_ENABLE_ERROR_RESPONSE);
		return tlm::TLM_COMPLETED;
	}
	if (len > 5 || wid < len) {
		receivedTrans.set_response_status(tlm::TLM_BURST_ERROR_RESPONSE);
		return tlm::TLM_COMPLETED;
	}
	unsigned int i;
	if (cmd == tlm::TLM_READ_COMMAND)
		for (i = 0; i < len; i = i + 1) {
			*(ptr + i) = *((unsigned char*)(memArray + adr + i));
		}
	else if (cmd == tlm::TLM_WRITE_COMMAND)
		for (i = 0; i < len; i = i + 1) {
			*((unsigned char*)(memArray + adr + i)) = *(ptr + i);
		}



		receivedTrans.set_response_status(tlm::TLM_OK_RESPONSE);
		delay = delay + sc_time(123, SC_NS);

		cout << "Current target = target[" << SocketID << "]" << endl;
	//}


	return tlm::TLM_COMPLETED;
}



void interconnect::nbMemWR()
{
	tlm::tlm_phase forwardPhase;
	sc_time processTime; // Processing time of initiator prior to call
	int SocketID;
	processTime = sc_time(0, SC_PS);
	bus.lock();
	cout << "locked" << endl;
	for (int i = 0; i < 111; i = i + 11) {


		tlm::tlm_command cmd = (tlm::tlm_command)(rand() % 2);
		if (cmd == tlm::TLM_WRITE_COMMAND) {
			data[0] = (sc_lv<8>) (i + 5);
			data[1] = (sc_lv<8>) (i + 6);
			data[2] = (sc_lv<8>) (i + 7);
			data[3] = (sc_lv<8>) (i + 8);
			data[4] = (sc_lv<8>) (i + 9);
		}

		nBlockWriteRead->set_command(cmd);
		nBlockWriteRead->set_address(i);
		nBlockWriteRead->set_data_ptr((unsigned char*)data);
		nBlockWriteRead->set_data_length(5);
		nBlockWriteRead->set_streaming_width(5);
		nBlockWriteRead->set_byte_enable_ptr(0);
		nBlockWriteRead->set_dmi_allowed(false);
		nBlockWriteRead->set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);

		forwardPhase = tlm::BEGIN_REQ;

		cout << (cmd ? 'W' : 'R') << ", @" << i << " data:";
		sc_lv<8> vv;
		for (int j = 0; j < 5; j++) { vv = data[j]; cout << vv << " "; }
		cout << " @time " << sc_time_stamp() << " delay=" << processTime << '\n';
		bus.unlock();
		tlm::tlm_sync_enum returnStatus;
		returnStatus = initiator_socket->
			nb_transport_fw(*nBlockWriteRead, forwardPhase, processTime);

		if (returnStatus == tlm::TLM_COMPLETED)
			doSomethingGood(*nBlockWriteRead, processTime);
		bus.unlock();
		cout << "unlocked" << endl;
	}
}


void interconnect::doSomethingGood(tlm::tlm_generic_payload& completeTrans,
	sc_time totalTime)
{
	if (completeTrans.is_response_error())
		SC_REPORT_ERROR("TLM-2", "error...\n");

	tlm::tlm_command cmd = completeTrans.get_command();
	uint64           adr = completeTrans.get_address();
	int* ptr = reinterpret_cast<int*>(completeTrans.get_data_ptr());

	cout << "Above was completed @time " << totalTime << '\n';
}