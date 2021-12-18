module nCounter(input initCount, enCount, clk, rst, input [7:0] nIn, output nEqual, output reg [7:0] nCounterOut);

	
	always @(posedge clk or posedge rst) begin
		if (rst) nCounterOut <= 8'b00000000;
		else if (initCount == 1) nCounterOut <= 8'b00000001;
		else if (enCount == 1) nCounterOut <= nCounterOut + 1;
			
		
	end
	
	assign nEqual = (nCounterOut == nIn) ? 1:0;
	
endmodule
