module sumAdderTop(input start, clk, rst, input [7:0] inBus, output done, output [15:0] adderOut);

	
	wire counterInit, counterEn, NregEn, sumRegEn, nEqual;
	
	sumAdderController controller(nEqual, start, clk, rst, done, counterInit, counterEn, NregEn, sumRegEn);
	sumAdderDatapath datapath(inBus, clk, rst, counterInit, counterEn, NregEn, sumRegEn, nEqual, adderOut);

endmodule



//module SATB();
//
//	reg start, clk, rst;
//	reg [7:0] inBus;
//	wire done;
//	wire [15:0] adderOut;
//
//	sumAdderTop UUT(start, clk, rst, inBus, done, adderOut);
//	
//	initial begin
//	
//		rst = 1;
//		inBus = 8'b00000000;
//		start = 0;
//		clk = 0;
//		
//		#100;
//		rst = 0;
//		#100;
//		inBus = 8'b00010000;
//		start = 1;
//		#200;
//		start = 0;
//	end
//	
//	
//	
//	always #50 clk = ~clk;
//
//endmodule
