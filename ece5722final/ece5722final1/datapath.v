module datapath(input [3:0] inBus, input clk, rst, nRegEn, xRegEn, init_t, init_r, initCount, ld_r, ld_t, enCount, output nEqual, output [15:0] adderOut);

	wire less, greater;
	wire [3:0] nCounter2comparator, Nreg2counter, demux2nreg, demux2xreg;
	wire[7:0] Xreg2multi;
	wire [15:0] Treg2adderandmulti, Rreg2adder, Adder2Rreg, Multi2Treg;
	


	Treg myTreg({8'b00000000, Multi2Treg[15:8]}, init_t, ld_t, clk, rst, Treg2adderandmulti);
	
	Rreg myRreg(adderOut, init_r, ld_r, clk, rst, Rreg2adder);
	
	demux myDemux(nRegEn, inBus, demux2xreg, demux2nreg);
	
	Adder myAdder(Treg2adderandmulti, Rreg2adder, adderOut);
	
	Multiplier myMulti({8'b00000000, Xreg2multi}, Treg2adderandmulti, Multi2Treg);
	
	Nreg myNreg(demux2nreg, nRegEn, clk, rst, Nreg2counter);
	
	XShiftreg myXReg(demux2xreg, xRegEn, clk, rst, Xreg2multi);
	
	nCounter myCounter(initCount, enCount, Nreg2counter, clk, rst, nEqual);
	
	//comparator myComparator(nCounter2comparator, Nreg2comparator, nEqual, less, greater);
	
	
	


endmodule
