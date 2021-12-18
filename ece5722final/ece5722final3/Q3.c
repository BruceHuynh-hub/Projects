#include <stdio.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"

#define PI 3.14159265359
#define START_REG_OFFSET 1 // fake values (will be different when we know addresses)
#define X_REG_OFFSET 2
#define DONE_REG_OFFSET 3
#define RESULT_REG_OFFSET 4
int main()
{

	while (1){
		int cot = 0;
		double result, input;

		x = IORD_ALTERA_AVALON_PIO_DATA(x_base);

	// adjusting input x before it goes into the accelerator

	if (x >= 0 && x < PI/2){

		cot = 0;
		input = x;	// no changes needed
		break;
	}

	else if (x >= PI/2 && x < PI){
		cot = 1; // negative cot needed
		input = x - (PI/2);
		break;
	}

	else if (x >= PI && x < ((3*PI)/2)){
		cot = 0;
		input = x - PI; // everything is the same but we need to shift
		break;
	}

	else if (x >= ((3*PI)/2) && x < (2*PI)){
		cot = 1; // negative cot needed
		input = x - (3*PI/2);
		break;
	}

	IOWR(TAN_ACCEL_BASE, X_REG_OFFSET, input); // putting new input into the x input
	IOWR(TAN_ACCEL_BASE, START_REG_OFFSET, 1); // start signal asserted

	IORD(TAN_ACCEL_BASE, DONE_REG_OFFSET);
	result = IORD(TAN_ACCEL_BASE, RESULT_REG_OFFSET);

	if (done == 1){ //wait for calculation to be done
		if (cot == 1){ // if additional cotangent was needed
			result = -1/result; // perform -cot(x) to get correct result
		}
		IOWR_ALTERA_AVALON_PIO_DATA(RESULT_base, result); // writing to PIO (7-Segment Display)
	}

	}
}
