#include "memWriterReader.h"
#include "memoryUnit.h"

SC_MODULE(memWriterReader_TB)
{
	memWriterReader *WR1;
	memoryUnit *MU1;
	sc_signal<int> start_ENDRESP;
	

	SC_CTOR(memWriterReader_TB)
	{
		WR1 = new memWriterReader("WR");
		MU1 = new memoryUnit("memory");
 		   WR1->memWRSocket.bind(MU1->memSocket);
		   WR1->start_ENDRESP(start_ENDRESP);
		   MU1->start_ENDRESP(start_ENDRESP);

		   
	}
};

