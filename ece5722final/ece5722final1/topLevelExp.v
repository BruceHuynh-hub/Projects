module topLevelExp(input [3:0] inBus, input start, clk, rst, output ready, output [15:0] y);

	wire nRegEn, xRegEn, init_t, init_r, initCount, ld_r, ld_t, enCount, nEqual;
	
	datapath myDatapath(inBus, clk, rst, nRegEn, xRegEn, init_t, init_r, initCount, ld_r, ld_t, enCount, nEqual, y);
	controller myController(start, nEqual, clk, rst, nRegEn, xRegEn, init_t, init_r, initCount, ld_r, ld_t, enCount, ready);

endmodule


module topLevelExpTB();

	reg [3:0] inBus;
	reg start, clk, rst;
	wire ready;
	wire [15:0] y;
	
	topLevelExp UUT(.inBus(inBus), .clk(clk) , .rst(rst) , .start(start), .ready(ready), .y(y));
	
	initial begin
	clk = 0;
	rst = 1;
	inBus = 0110;
	start = 0;
	#50;
	rst = 0;
	
	#200;
	start = 1;
	inBus = 4'b1111;
	#400;
	inBus = 4'b0001;
	#200 inBus = 4'b0000;
	#400 start = 0;
	
	
	end
	
	
	always #100 clk = ~clk; 
	
endmodule
