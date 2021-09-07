module sequence_detector(input j, clk, rst, co, output w, init, en);

	parameter [4:0] reset = 3'b000, got1 = 3'b001, got10 = 3'b010, got101 = 3'b011, got1011 = 3'b100, got10110 = 3'b101;
	reg[4:0] pres_state, next_state;
	reg[7:0] firsttime;
	reg pulse, outputon;
	
	initial firsttime = 0;
	
	always @ (posedge clk) begin
		firsttime = firsttime + 1;
		if (co == 1 || firsttime == 1) begin
			pulse = 1;
			outputon = 0;
			end
		if (next_state == got10110) begin
			pulse = 0;
			outputon = 1;

			end
		if (firsttime == 8'b11111111)
		
			firsttime = 8'b00000010;
		
	end
	



	always @ (pres_state or j) begin : combinational
	next_state = 0;

	if (pulse == 1) begin
		case (pres_state)

			reset: begin
			if (j == 1'b1)
			next_state = got1;
			else
			next_state = reset;
			end

			got1: begin
			if (j == 1'b0)
			next_state = got10;
			else
			next_state = got1;
			end

			got10: begin
			if (j == 1)
			next_state = got101;
			else
			next_state = reset;
			end

			got101: begin
			if (j == 1)
			next_state = got1011;
			else
			next_state = got10;
			end

			got1011: begin
			if (j == 0)
			next_state = got10110;
			else
			next_state = got1;
			end

			got10110: begin
			if (j == 0)
			next_state = reset;
			else
			next_state = got101;
			end

			default next_state = reset;
			
		endcase
	end

	end



	always @ (posedge clk or posedge rst) begin
		if (rst)
			pres_state <= reset;
		else
			pres_state <= next_state;
	end

	assign w = outputon;
	assign init = (pres_state == got10110) ? 1 : 0;
	assign en = w;
	


endmodule



module sequence_detector_test_rdm;

	reg j, clk, rst, co;
	wire w, init, en;

	sequence_detector uut (j, clk, rst, co, w, init, en);

	initial begin

		co = 1'b1; clk = 1'b1; rst = 1'b1; j = 1'b0;
		
	end

	initial #25 rst = 1'b0;
	initial #10 co = 1'b0;

	always #30 clk = ~clk;
	always #15 j = $random;
	

endmodule



module sequence_detector_test_fixed;

	reg j, clk, rst, co;
	wire w, init, en;

	sequence_detector uut (j, clk, rst, co, w, init, en);

	initial begin

		co = 1'b1; clk = 1'b1; rst = 1'b1; j = 1'b1;
		
	end

	initial #5 rst = 1'b0;
	initial #5 co = 1'b0;
	always #30 clk = ~clk;

	
	
	always begin 
	j = 1'b1; #60; j = 1'b0; #60; j = 1'b1; #60; j = 1'b1; #60; j = 1'b0; #60; #1200; co = 1'b1; #2; co = 1'b0;
	end

endmodule
