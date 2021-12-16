#include <systemc.h>
#include "tlm_utils/simple_initiator_socket.h"
#include "tlm_utils/simple_target_socket.h"
#include "tlm.h"
#include <iostream>
using std::cout;


class interconnect : public sc_module {
public:
    sc_mutex bus;
    tlm_utils::simple_target_socket_tagged<interconnect, 32> target_socket[2];
    tlm_utils::simple_initiator_socket<interconnect, 32> initiator_socket;



public: 
    //SC_CTOR(interconnect) : target_socket("target_socket"){
        interconnect(sc_core::sc_module_name name) :
           sc_core::sc_module(name), nBlockWriteRead(0) {

                target_socket[0].register_nb_transport_fw(this, &interconnect::nb_transport_fw, 0);
                target_socket[1].register_nb_transport_fw(this, &interconnect::nb_transport_fw, 1);

                //for (int i = 0; i < 256; i++)
                //    memArray[i] = (sc_lv<8>) (i % 256 + 192);
                //nBlockWriteRead = new tlm::tlm_generic_payload();
                //for (int i = 0; i < 4; i++) *(data + i) = i + 192;
                //SC_THREAD(nbMemWR);
        }

    //void thread_1();
    //void thread_2();
    sc_lv<8> data[5];
    sc_lv<8> memArray[256];
    tlm::tlm_generic_payload* nBlockWriteRead;
    void doSomethingGood(tlm::tlm_generic_payload&, sc_time);
    void nbMemWR();
    virtual tlm::tlm_sync_enum nb_transport_fw(int SocketID, tlm::tlm_generic_payload&, tlm::tlm_phase&, sc_time&);
};
    
