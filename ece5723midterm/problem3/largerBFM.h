#include <systemc.h>
#include <iostream>

template <int NumClk>
SC_MODULE(largerBFM) {
public:
	sc_in<sc_logic> start, stop, rst, clk;
	sc_in<sc_lv<8>> inBus;
	sc_out<sc_lv<8>> outBus;
	enum state_types { initialize, wait_start, started, wait_stop };
	sc_signal<state_types> Nstate, Pstate;

	sc_lv<8> max;

	SC_CTOR(largerBFM) {

		SC_THREAD(operation);
		sensitive << clk << rst << Pstate;
	}
	void operation();
};

template <int NumClk>
void largerBFM<NumClk>::operation() {
	while (true) {

		if (rst == '1') {
			//
			Pstate, Nstate = initialize;
			max = "00000000";
		}
		else if (clk == '1' & clk->event()) {
			for (int i = 0; i < NumClk; i++) {
				wait(clk->posedge_event());

				Pstate = Nstate;
				cout << "Pstate: " << Pstate << " *** Nstate: " << Nstate << endl;
				cout << " start: " << start << " *** stop:   " << stop << endl;
				if (Pstate == initialize and start == '1') {
					Nstate = wait_start;
					outBus = "ZZZZZZZZ";
				}
				else if (Pstate == wait_start and start == '0') {
					Nstate = started;
					outBus = "ZZZZZZZZ";
				}
				else if (Pstate == started and stop == '1') {
					Nstate = wait_stop;
					outBus = "ZZZZZZZZ";
				}
				else if (Pstate == wait_stop and stop == '0') {
					Nstate = initialize;
					outBus = max;
				}
				if (Nstate == 2) {
					cout << "max: " << max << endl;
					if (inBus->read().to_uint() > max.to_uint()) {
						max = inBus->read().to_uint();
					}
				}
			}
		}
		wait();
	}
}