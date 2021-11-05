module Adder4x16(input start, clk, rst, input [3:0] dataInA, input [3:0] dataInB, output done, overflow_flag);
	parameter [2:0] initialS = 3'b000, wait_on_start = 3'b001, adding = 3'b010, turnToAdd = 3'b011, finished = 3'b100;
	reg enableAdd, counterStart;
	reg [2:0] nstate, pstate;
	wire [3:0] sumOut, counter;
	reg [3:0] reg4bit [15:0];
	reg [63:0] reg64;
	reg [3:0] hold;
	integer i;
	reg carryIn = 0;
	wire carryOut;
	

	Counter myCounterInstance (.init(counterStart), .clk(clk), .rst(rst), .counterOut(counter));
	Adder myAdderInstance (.dataA(dataInA), .dataB(dataInB), .initAdd(enableAdd), .cin(carryIn), .cout(carryOut), .sum(sumOut));
	
	// state switching
	always @ (pstate or start or counter) begin: combinational
		nstate = 0;
		case (pstate)
		
			initialS: begin
				if (start == 0)
					nstate = initialS;
				else if (start == 1)
					nstate = wait_on_start;
			end
			
			wait_on_start: begin
			
				if (start == 1)
					nstate = wait_on_start;
				else if (start == 0)
					nstate = adding;
			end
			
			adding: begin
				nstate = turnToAdd;
			end
			
			turnToAdd: begin
				if (counter != 4'b1111)
					nstate = turnToAdd;
				else if (counter == 4'b1111)
					nstate = finished;
			end
			
			finished: begin
				if (start == 0)
					nstate = finished;
				else if (start == 1)
					nstate = wait_on_start;
			end
			
		endcase
	end

	
	
	always @(pstate or counter) begin: combinationalAssignment
	
		case (pstate)
		
		initialS: begin
		end
		
		wait_on_start: begin
		end
		
		adding: begin
			enableAdd = 1;
		end
		
		turnToAdd: begin
			counterStart = 1;
			reg4bit[counter][3:0] = sumOut;

		end
		
		finished: begin
			counterStart = 0;
			reg64[3:0]   = reg4bit[0] [3:0];
			reg64[7:4]   = reg4bit[1] [3:0];
			reg64[11:8]  = reg4bit[2] [3:0];
			reg64[15:12] = reg4bit[3] [3:0];
			reg64[19:16] = reg4bit[4] [3:0];
			reg64[23:20] = reg4bit[5] [3:0];
			reg64[27:24] = reg4bit[6] [3:0];
			reg64[31:28] = reg4bit[7] [3:0];
			reg64[35:32] = reg4bit[8] [3:0];
			reg64[39:36] = reg4bit[9] [3:0];
			reg64[43:40] = reg4bit[10][3:0];
			reg64[47:44] = reg4bit[11][3:0];
			reg64[51:48] = reg4bit[12][3:0];
			reg64[55:52] = reg4bit[13][3:0];
			reg64[59:56] = reg4bit[14][3:0]; 
			reg64[63:60] = reg4bit[15][3:0];
		end
	
		endcase
	end
	
	
	assign done = (pstate == finished) ? 1:0;
	assign overflow_flag = (carryOut == 1 & counter == 4'b1111) ? 1 : 0;
	
	
	
// putting next state into present state and resetting
	always @(posedge clk or posedge rst) begin: sequential
	
		if (rst == 1) begin
			pstate = initialS;
			for (i = 0; i < 16; i = i + 1)
				reg4bit[i][3:0] <= 3'b000;
		end
		
		else
			pstate <= nstate;
			carryIn <= carryOut;
	end
	
	
	
endmodule






module Adder (input [3:0] dataA, dataB, input initAdd, cin, clk, output cout, output wire [3:0] sum);

	assign {cout, sum} = (initAdd) ? (dataA + dataB + cin):0;
	
endmodule








module Counter (input init, clk, rst, output [3:0] counterOut);

	reg [3:0] count = 4'b000;
	
	always @(posedge clk or posedge rst) begin: sequential
		
		if (rst == 1)
			count <= 4'b0000;
		else if (init == 1 && count != 4'b1111)
			count <= count + 1;
			else if (init != 1 | count == 4'b1111)
				count <= 4'b0000;

		
	end
	
	assign counterOut = count;

endmodule


module Adder4x16TB ();

	reg start, clk, rst;
	reg [3:0] dataInA, dataInB;
	wire done;
	
	Adder4x16 UUT (start, clk, rst, dataInA, dataInB, done);
	
	initial begin
	
// 1 value entire time
//	clk = 0;
//	dataInA = 4'b000;
//	dataInB = 4'b000;
//	start = 0;
//	rst = 1;
//	#30;
//	rst = 0;
//	#30;
//	dataInA = 4'b1010;
//	dataInB = 4'b0100;
//	start = 1;
//	#200;
//	start = 0;
//	#2000;
	
	
// 2 changed values
//	clk = 0;
//	dataInA = 4'b000;
//	dataInB = 4'b000;
//	start = 0;
//	rst = 1;
//	#30;
//	rst = 0;
//	#30;
//	dataInA = 4'b1010;
//	dataInB = 4'b0100;
//	start = 1;
//	#200;
//	start = 0;
//	#1000;
//	dataInA = 4'b0011;
//	#500;
//	dataInB = 4'b1000;
//	#1000;

// 1 changed values with carryIn/carryOut
//	clk = 0;
//	dataInA = 4'b000;
//	dataInB = 4'b000;
//	start = 0;
//	rst = 1;
//	#30;
//	rst = 0;
//	#30;
//	dataInA = 4'b1010;
//	dataInB = 4'b0100;
//	start = 1;
//	#200;
//	start = 0;
//	#1000;
//	dataInA = 4'b1101;
//	#500;
//	dataInB = 4'b0100;
//	#1000;

// 1 changed values with carryIn/carryOut and additional start pulse after ending
	clk = 0;
	dataInA = 4'b000;
	dataInB = 4'b000;
	start = 0;
	rst = 1;
	#30;
	rst = 0;
	#30;
	dataInA = 4'b1010;
	dataInB = 4'b0100;
	start = 1;
	#200;
	start = 0;
	#1000;
	dataInA = 4'b1101;
	#500;
	dataInB = 4'b0100;
	#2000;
	start = 1;
	#200;
	start = 0;
	dataInA = 4'b0010;
	dataInB = 4'b0100;
	#2000;
//	
	
	
	end
	
	always begin
	#100 clk = ~clk;
	end
	
	
endmodule
