#include <systemc.h>
#include <iostream>


template <int NumClk>
SC_MODULE(averageBFM) {
	sc_in<sc_logic> rst, clk, start, stop;
	sc_in<sc_lv<8>> inBus;
	sc_out <sc_lv<8>> outBus;
	sc_lv<8> currHold;
	enum state_types {INITIALIZE, WAIT_ON_START, STARTED, ACTIVE, ACTIVE2, ACTIVE3, WAIT_ON_END};
	sc_signal<state_types> Pstate, Nstate;
	sc_lv<8> currInBus;

	SC_CTOR(averageBFM) {
		SC_THREAD(operation);
		sensitive << clk << rst;
		SC_THREAD(averaging);
		sensitive << inBus;
		SC_THREAD(stateReset);
		sensitive << Nstate << Pstate;
		SC_THREAD(stateChanges);
		sensitive << start << stop << Pstate;
	}
	void operation();
	void averaging();
	void stateReset();
	void stateChanges();
};

template <int NumClk>
void averageBFM<NumClk>::stateChanges() {
	while(true){
		switch (Pstate) {
		case INITIALIZE:
			if (start == '0') Nstate = INITIALIZE;
			else Nstate = WAIT_ON_START;
			break;

		case WAIT_ON_START:
			if (start == '1') Nstate = WAIT_ON_START;
			else Nstate = STARTED;
			break;

		case STARTED:
			Nstate = ACTIVE;
			break;

		case ACTIVE:
			if (stop == '0') Nstate = ACTIVE2;
			else Nstate = WAIT_ON_END;
			break;

		case ACTIVE2:
			if (stop == '0') Nstate = ACTIVE3;
			else Nstate = WAIT_ON_END;
			break;

		case ACTIVE3:
			if (stop == '0') Nstate = ACTIVE;
			else Nstate = WAIT_ON_END;
			break;

		case WAIT_ON_END:
			if (stop == '1') Nstate = WAIT_ON_END;
			else Nstate = INITIALIZE;
			break;

		default:
			Nstate = INITIALIZE;
			break;
		}
		wait();
	}
}

template <int NumClk>
void averageBFM<NumClk>::stateReset() {
	while (true) {
		if (Pstate == INITIALIZE) {
			outBus = currHold;
		}
		else {
			outBus = "XXXXXXXX";
		}
		if (Pstate == WAIT_ON_START) {
			currHold = "00000000";
		}
		wait();
	}
}

template <int NumClk>
void averageBFM<NumClk>::averaging() {
	while (true){
		if (Pstate != INITIALIZE && Pstate != WAIT_ON_START /*&& Pstate != STARTED*/) {
			cout << "currHold: " << currHold << "inBus read: " << inBus << endl;
			if (currHold != "00000000") {
				currHold = (inBus->read().to_uint() + currHold.to_uint()) / 2;
				cout << "average: " << currHold << endl;
			}
			else {
				currHold = (inBus->read().to_uint());

			}
		}
		wait();
	}

}

template <int NumClk>
void averageBFM<NumClk>::operation() {

	while (true) {
		if (rst == '1') {
			currHold = "00000000";
		}
		else if (clk->event() && clk == '1') {
			for (int i = 0; i < NumClk; i++) {
				wait(clk->posedge_event());

				Pstate = Nstate;

				cout << "Pstate: " << Pstate << " *** Nstate: " << Nstate << endl;
				cout << " start: " << start << " *** stop:   " << stop << endl;
				cout << "average: " << currHold << endl;
			}
		}
		wait();
	}
}

