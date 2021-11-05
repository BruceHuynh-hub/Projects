#include "largerCU.h";


// putting Nstate into Pstate
void largerCU::seq_function() {
	while (true) {
		if (rst == '1') {
			Pstate = initialize;
		}
		else if (clk->event() && (clk == '1')) {
			Pstate = Nstate;
			cout << "Pstate: " << Pstate << " *** Nstate: " << Nstate << endl;
			cout << " start: " << start << " *** stop:   " << stop << endl;

		}
		wait();
	}
}

// conditions for switching states
void largerCU::comboState_function() {
	Nstate = initialize;
	switch (Pstate) {

	case initialize:
		if (start == '1') {
			Nstate = wait_start;
		}
		else {
			Nstate = initialize;
		}
		break;
	case wait_start:
		if (start == '0') {
			Nstate = started;
		}
		else {
			Nstate = wait_start;
		}
		break;
	case started:
		if (stop == '1') {
			Nstate = wait_stop;
		}
		else {
			Nstate = started;
		}
		break;
	case wait_stop:
		if (stop == '0') {
			Nstate = initialize;
		}
		else {
			Nstate = wait_stop;
		}
		break;
	}
}

// Outputs for every state
void largerCU::comboOutput_function() {
	//triEn = SC_LOGIC_0;
	//regEn = SC_LOGIC_0;
	switch (Pstate) {

	case initialize:
		triEn = SC_LOGIC_1;
		regEn = SC_LOGIC_0;
		break;

	case wait_start:
		triEn = SC_LOGIC_0;
		regEn = SC_LOGIC_0;
		break;
	case started:
		triEn = SC_LOGIC_0;
		regEn = SC_LOGIC_1;
		break;
	case wait_stop:
		triEn = SC_LOGIC_0;
		regEn = SC_LOGIC_1;
		break;
	}

}