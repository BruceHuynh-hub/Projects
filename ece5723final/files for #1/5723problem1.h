#include <systemc.h>
#include <iostream>
#include <sysc/datatypes/int/sc_uint.h>


using namespace sc_core;
using namespace sc_dt;



SC_MODULE(cosTaylorSeries) {
	sc_in<sc_logic> clk, rst, start;
	sc_in<float> x;
	sc_out<float> out;
	sc_out<sc_logic> ready;
	enum state_types { INITIALIZE, WAIT_ON_START, ACTIVE, DONE};
	sc_signal<state_types> state;
	sc_signal<float> x_reg;


	double inBusval;

	SC_CTOR(cosTaylorSeries) {
		SC_THREAD(operation);
		sensitive << clk << rst;

	}

	void operation();



};

