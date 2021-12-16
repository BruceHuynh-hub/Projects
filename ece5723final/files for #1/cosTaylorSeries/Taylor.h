#include <systemc.h>
#include <iostream>
#include <sysc/datatypes/fx/sc_fixed.h>


using namespace sc_core;
using namespace sc_dt;

typedef sc_dt::sc_fixed<8, 7> fixed_type;

SC_MODULE(cosTaylorSeries) {
	sc_in<sc_logic> clk, rst, start;
	sc_in<sc_lv<8>> x;
	sc_out<sc_lv<8>> out;
	sc_out<sc_logic> ready;
	enum state_types { INITIALIZE, WAIT_ON_START, ACTIVE, DONE};
	sc_signal<state_types> state;

	double inBusval;

	SC_CTOR(cosTaylorSeries) {
		SC_THREAD(operation);
		sensitive << clk << rst;

	}

	void operation();



};

