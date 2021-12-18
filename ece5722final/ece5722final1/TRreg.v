module Rreg (input [15:0] load, input init, loadEn, clk, rst, output reg [15:0] loadOut);


	always @(posedge clk or posedge rst) begin
	
		if (rst) loadOut <= 16'b0000000000000000;
		else if (init) loadOut <= 16'b0000000100000000;
		else if (loadEn) loadOut <= load;
	
	end

endmodule

module Treg (input [15:0] load, input init, loadEn, clk, rst, output reg [15:0] loadOut);


	always @(posedge clk or posedge rst) begin
	
		if (rst) loadOut <= 16'b0000000000000000;
		else if (init) loadOut <= 16'b0000000100000000;
		else if (loadEn) loadOut <= load;
	
	end

endmodule




module Nreg (input [3:0] load, input loadEn, clk, rst, output reg [3:0] loadOut);

	always @(posedge clk or posedge rst) begin
	
		if (rst) loadOut <= 4'b0000;

		else if (loadEn) loadOut <= load;
	end
	
endmodule


module XShiftreg (input [3:0] load, input loadEn, clk, rst, output reg [7:0] loadOut);

	reg FOLBits;
	
	always @(posedge clk or posedge rst) begin
	
		if (rst) loadOut <= 8'b00000000;

		else if (loadEn) loadOut <= {load, loadOut[7:4]};
		
//		else if (loadEn) loadOut
		
		
	end
	
endmodule
