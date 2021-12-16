#include "stackPushPop.h"

void transmitter::pushSome()
{
	int i = 0;
	sc_lv<8> data;
	for(i=0; i<=43; i++)
	{

		wait(3, SC_NS);
		data = (sc_lv<8>) i;
		out->b_push(sc_lv<8>(i));
			cout << "Data: " << data << " was written at: "
			     << sc_time_stamp() << '\n';

	}
}

void receiver::popThem()
{
	int i = 0;
	sc_lv<8> data;
	for(i=0; i<=48; i++)
	{
		wait(7, SC_NS);
		in->b_pop(data);
			cout << "Data: " << data << " popped at: "
			     << sc_time_stamp() << '\n';

	}
}
