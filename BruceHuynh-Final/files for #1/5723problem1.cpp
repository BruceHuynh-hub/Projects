#include "5723problem1.h"



void cosTaylorSeries::operation() {

	int n = 8;
	int numClk = n + 2;
	float term = 1;
	float exp = 1;
	while (true) {

		if (rst == '1') {
			out = 0;
			state = INITIALIZE;

		}
		else if (clk == '1' && clk->event()) {
			switch (state) {
			case (INITIALIZE):

				if (start == '0') {
					state = INITIALIZE;
				}
				else if (start == '1') {
					state = WAIT_ON_START;
				}
				break;
			case (WAIT_ON_START):
				if (start == '1') {
					state = WAIT_ON_START;
				}
				else if (start == '0') {
					state = ACTIVE;
				}
				break;

			case (ACTIVE):
				x_reg = x->read();
				wait(clk->posedge_event());

				for (int i = 1; i <= n; i++) {
					term = term * (-1) * x_reg.read() * x_reg.read() / (2 * i * (2 * i -1));
					exp = exp + term;

				}

				for (int i = 0; i < numClk - 1; i++)
					wait(clk->posedge_event());

				cout << "value of cos(" << x << ") is: " << exp << endl;
				out = exp;
				state = DONE;
				break;
			case (DONE):
				ready = SC_LOGIC_1;
				state = INITIALIZE;

				cout << "number of iterations is " << n << endl;
				break;
			}
			}
		wait();
		}



	}
