module sumAdderDatapath(input [7:0] inBus, input clk, rst, counterInit, counterEn, NregEn, sumRegEn, output nEqual, output [15:0] dataOut);

	wire [15:0] counter2Adder, adder2sumReg;
	//wire [15:0] sumReg2Adder;
	wire [7:0] Nreg2counter;


	Adder myAdder(dataOut, counter2Adder, adder2sumReg);
	Nreg myNreg(inBus, NregEn, clk, rst, Nreg2counter);
	sumReg mysumReg(adder2sumReg, sumRegEn , clk, rst , dataOut);
	nCounter mynCounter(counterInit, counterEn, clk, rst, Nreg2counter, nEqual, counter2Adder);



endmodule
