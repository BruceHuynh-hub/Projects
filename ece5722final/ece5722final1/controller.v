module controller(input start, nEqual, clk, rst, output reg nRegEn, xRegEn, init_t, init_r, initCount, ld_r, ld_t, enCount, ready);

	reg [3:0] pstate, nstate;
	parameter idle = 3'b000, getN = 3'b001, getX1 = 3'b010, getX2 = 3'b011, starting = 3'b100, xMul = 3'b101, tAdd = 3'b110;
	
	
	always @(posedge clk or posedge rst) begin
		if (rst) pstate <= idle;
			else
				pstate <= nstate;
	end

	always @(pstate or start or nEqual) begin
	
		case (pstate)
		
			idle: begin
			
				if (start == 0) 
					nstate = idle;
					
				else if (start == 1)
					nstate = getN;
			
			end
			
			getN: begin
				nstate = getX1;
			end
			
			getX1: begin
				nstate = getX2;
			end
			
			getX2 : begin
				nstate = starting;
			end
			
			starting : begin
			
				if (start == 1)
					nstate = starting;
				else if (start == 0)
					nstate = xMul;
			
			end
			
			xMul: begin
				
				if (nEqual == 0)
					nstate = tAdd;
				else if (nEqual == 1) // even if it gets interrupted after multiplication, the addition wont be affected.
					nstate = idle;
			end
			
			tAdd: begin
				
				if (nEqual == 0)
					nstate = xMul;
				else if (nEqual == 1)
					nstate = idle;
				
			end
	
		endcase
	
	end
	
	
		always @(pstate or start or nEqual) begin
			
					nRegEn = 0;
					xRegEn = 0;
					init_t = 0;
					init_r = 0;
					initCount = 0;
					ld_t = 0;
					ld_r = 0;
					enCount = 0;
					ready = 0;
			
			case (pstate)
			
				idle: begin

					ready = 1;
					
				end
				
				getN: begin
					
					nRegEn = 1;
					initCount = 1;
			
				end
				
				getX1: begin
				
					xRegEn = 1;
				
				end
				
				getX2 : begin
				
					xRegEn = 1;
				
				end
				
				starting : begin
				
					init_t = 1;
					init_r = 1;

				
				end
				
				xMul: begin

					ld_t = 1;
				
				end
				
				tAdd: begin
				
					ld_r = 1;
					enCount = 1;
				
				end
				


		endcase
	
	end
	

endmodule
