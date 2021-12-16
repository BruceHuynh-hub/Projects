#include "memWriterReader.h"
#include "memoryUnit.h"
#include "interconnect.h"

SC_MODULE(memWriterReader_TB)
{
	memWriterReader *WR1;
	memWriterReader* WR2;
	memoryUnit *MU1;
	interconnect *IN1;

	SC_CTOR(memWriterReader_TB)
	{
		WR1 = new memWriterReader("WR1");
		WR2 = new memWriterReader("WR2");
		MU1 = new memoryUnit("memory");
		IN1 = new interconnect("interconnect");
 		//WR1->memWRSocket.bind(MU1->memSocket);
		WR1->memWRSocket.bind(IN1->target_socket[0]);
		WR2->memWRSocket.bind(IN1->target_socket[1]);
		IN1->initiator_socket.bind(MU1->memSocket);

	}
};

