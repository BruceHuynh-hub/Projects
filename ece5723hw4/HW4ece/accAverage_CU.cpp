#include "accAverage_CU.h"

void accAverage_CU::comb_S_function() {
	Nstate = INITIALIZE;

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
		//else Nstate = WAIT_ON_END;
		break;

	case ACTIVE2:
		if (stop == '0') Nstate = ACTIVE3;
		//else Nstate = WAIT_ON_END;
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
}

void accAverage_CU::comb_O_function() {
	enableReg = SC_LOGIC_0;
	selMux = SC_LOGIC_0;
	selTri = SC_LOGIC_0;

	switch (Pstate) {
	case INITIALIZE:
		selTri = SC_LOGIC_1;
		shift_en = SC_LOGIC_0;
		parallel_load_en = SC_LOGIC_0;
		break;

	case STARTED:
		selMux = SC_LOGIC_1;
		enableReg = SC_LOGIC_1;

		break;

	case ACTIVE:
		shift_en = SC_LOGIC_1;
		parallel_load_en = SC_LOGIC_1;

		break;

	case ACTIVE2:
		//shift_en = SC_LOGIC_1;
		//parallel_load_en = SC_LOGIC_0;

		break;

	case ACTIVE3:

	case WAIT_ON_END:
		enableReg = SC_LOGIC_1;
		break;

	default:
		enableReg = SC_LOGIC_0;
		selMux = SC_LOGIC_0;
		selTri = SC_LOGIC_0;
		break;
	}
}

void accAverage_CU::seq_function() {
	while (true) {
		if (rst == '1') {
			Pstate = INITIALIZE;
		}
		else if (clk->event() && (clk == '1')) {
			Pstate = Nstate;
			cout << "Pstate: " << Pstate << " *** Nstate: " << Nstate << endl;
			cout << " start: " << start << " *** stop:   " << stop << endl;


		}
		wait();
	}
}