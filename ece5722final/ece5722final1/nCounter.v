module nCounter(input initCount, enCount, input [3:0] NregIn, input clk, rst, output nEqual);

	reg [3:0] nCounterOut;
	
	always @(posedge clk or posedge rst) begin
		if (rst) nCounterOut <= 4'b0000;
		else if (initCount == 1) nCounterOut <= 4'b0000;
		else if (enCount == 1) nCounterOut <= nCounterOut + 1;
			
	end
	
	assign nEqual = (nCounterOut == (NregIn - 2)) ? 1:0;

	
endmodule
