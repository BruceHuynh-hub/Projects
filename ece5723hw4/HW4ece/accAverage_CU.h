#include <systemc.h>


SC_MODULE(accAverage_CU){
public:
	sc_in<sc_logic> start, stop, rst, clk;
	sc_out<sc_logic> enableReg, selMux, selTri, parallel_load_en, shift_en;

	enum state_types {INITIALIZE, WAIT_ON_START, STARTED, ACTIVE, ACTIVE2, ACTIVE3, WAIT_ON_END};

	sc_signal<state_types> Nstate, Pstate;

	SC_CTOR(accAverage_CU) {
		SC_THREAD(seq_function);
		sensitive << rst << clk;
		SC_METHOD(comb_S_function);
		sensitive << start << stop << Pstate;
		SC_METHOD(comb_O_function);
		sensitive << Pstate;
	}
	void seq_function();
	void comb_S_function();
	void comb_O_function();
};