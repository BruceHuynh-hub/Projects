#include <systemc.h>

SC_MODULE(largerCU) {

public:
	sc_in<sc_logic> start, stop, rst, clk;
	sc_out<sc_logic> triEn, regEn;

	enum state_types { initialize, wait_start, started, wait_stop};

	sc_signal<state_types> Nstate, Pstate;

	SC_CTOR(largerCU) {
		SC_THREAD(seq_function);
		sensitive << rst << clk;
		SC_METHOD(comboState_function);
		sensitive << start << stop << Pstate;
		SC_METHOD(comboOutput_function);
		sensitive << Pstate;


	}
	void seq_function();
	void comboState_function();
	void comboOutput_function();
};