#include "Taylor.h"



void cosTaylorSeries::operation() {
	double res = 1, sign = 1, factorial = 1, pow = 1;
	double sum;
	int n = 8;
	while (true) {





		if (rst == '1') {
			out = "00000000";
			state = INITIALIZE;
			sum = 0;
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

				inBusval = x->read().to_uint();
				inBusval = inBusval / 128; // shift 7 bits (1 int 7 fractions)

				

				for (int i = 1; i < 5; i++) {
					sign = sign * -1;
					factorial = factorial * (2 * i - 1) * (2 * i);
					pow = pow * inBusval * inBusval;
					res = res + sign * pow / factorial;
				}

				//out->write(res);



				state = DONE;
				break;

			case (DONE):

				ready = SC_LOGIC_1;
				state = INITIALIZE;

				break;
			}

			}
		wait();
		}



	}
