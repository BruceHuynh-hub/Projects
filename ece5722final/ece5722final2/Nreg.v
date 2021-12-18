module Nreg (input [7:0] load, input loadEn, clk, rst, output reg [7:0] loadOut);

	always @(posedge clk or posedge rst) begin
	
		if (rst) loadOut <= 8'b00000000;

		else if (loadEn) loadOut <= load;
	end
	
endmodule


module sumReg (input [15:0] load, input loadEn, clk, rst, output reg [15:0] loadOut);

	always @(posedge clk or posedge rst) begin
	
		if (rst) loadOut <= 16'b0000000000000000;
		else if (loadEn) loadOut <= load;
	end


endmodule

