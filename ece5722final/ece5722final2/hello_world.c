#include <stdio.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"

int main()
{

	while(1){
		int zero = 0;
		int inputData = IORD_ALTERA_AVALON_PIO_DATA(SWITCHIN_BASE);

		int result = ALT_CI_SUMADDER_0(inputData, zero);
		IOWR_ALTERA_AVALON_PIO_DATA(DATAOUT_BASE, result);

	}
}
