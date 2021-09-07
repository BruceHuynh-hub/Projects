module my_counter (input clk, rst, en, init, output co);

reg [5:0] current;
reg pulse;

always @ (posedge clk) begin

	if (init)
		pulse = 1'b1;
		
	if (current == 6'b100000)
		pulse = 1'b0;


end


always @ (posedge clk) begin

	if (rst || current == 6'b100000)
		current <= 6'b000000;
	else if (en && pulse)
		current = current + 1'b1;
		
	
		
end


assign co = (current == 6'b100000) ? 1 : 0;



endmodule


module my_counter_test;
	reg clk, rst, en, init;
	reg current, pulse;
	wire co;
	my_counter uut (clk, rst, en, init, co);
	
	initial begin
	clk = 1'b0;
	rst <= 1'b1;
	#5 rst <= 1'b0;
	#10 en <= 1'b1;
	init = 1'b1;
	end
	
	always @ (posedge clk) begin
	#20 init = 1'b0;
	#2000;
	#20 init = 1'b1;
	#20 init = 1'b0;
	end
	
	
always #5 clk = ~clk;


endmodule
