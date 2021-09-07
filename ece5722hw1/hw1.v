module moore_with_counter(input j, clk, rst, output w);
	
	wire detector_en_to_counter;
	wire detector_init_to_counter;
	wire counter_clockout_to_detector;

	my_counter Counter32 (.clk (clk), .rst (rst), .en (detector_en_to_counter), .init (detector_init_to_counter), .co (counter_clockout_to_detector));
	sequence_detector SequenceD (.j (j), .clk (clk), .rst (rst), .co (counter_clockout_to_detector), .w (w), .init (detector_init_to_counter), .en (detector_en_to_counter));
	
endmodule

module moore_with_counter_test_fixed;
	
	reg j, clk, rst;
	wire w;
	
	moore_with_counter uut (j, clk, rst, w);
	
	
	initial begin
	
		clk = 1'b1; rst = 1'b1; j = 1'b1;
		
	end
	
	initial #5 rst = 1'b0;
	always #30 clk = ~clk;
	
	always begin 
	j = 1'b1; #60; j = 1'b0; #60; j = 1'b1; #60; j = 1'b1; #60; j = 1'b0; #60;
	end
	
endmodule


module moore_with_counter_test_rdm;

	reg j, clk, rst, co;
	wire w;

	moore_with_counter uut (j, clk, rst, w);

	initial begin

		clk = 1'b1; rst = 1'b1; j = 1'b0;
		
	end

	initial #25 rst = 1'b0;

	always #30 clk = ~clk;
	always #15 j = $random;
	

endmodule
