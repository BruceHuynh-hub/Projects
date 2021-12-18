module sumAdderController (input nEqual, start, clk, rst, output done, output reg counterInit, counterEn, NregEn, sumRegEn);

	parameter idle = 2'b00, wait_start_fin = 2'b01, calculating = 2'b10, doneState = 2'b11;
	reg [1:0] pstate, nstate;

	always @(posedge clk) begin
	
		if (rst) pstate <= idle;
		else pstate <= nstate;

	end

	always @(pstate or start or nEqual) begin
	
		case (pstate)
		
			idle: begin
			
				if (start == 0)
					nstate = idle;
					
				else if (start == 1)
					nstate = wait_start_fin;
			
			end
			
			wait_start_fin: begin
			
				if (start == 1)
					nstate = wait_start_fin;
				else if (start == 0)
					nstate = calculating;
			
			end
			
			calculating: begin
			
			
			
				if (nEqual == 1)
					nstate = doneState;
				else if (nEqual == 0)
					nstate = calculating;
			
			end
			
			doneState: begin
			
				nstate = idle;
			
			end
			
		endcase
		
	end
	
	
	assign done = (pstate == doneState) ? 1:0;

	
	always @(pstate) begin
		counterInit = 0;
		NregEn = 0;
		sumRegEn = 0;
		counterEn = 0;
	
		case (pstate)
		
			idle: begin
			
			
			end
			
			wait_start_fin: begin
				
				counterInit = 1;
				NregEn = 1;
				
			end
			
			calculating: begin
			
				sumRegEn = 1;
				counterEn = 1;
			
			end
			
			doneState: begin
			
			
			
			end
			
		endcase
		
	end
	
	
endmodule
