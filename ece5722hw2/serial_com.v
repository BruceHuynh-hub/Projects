module serial_com(input serial_in, clk, rst, output valid, port0, port1, port2, port3);
    reg [8:0] seq;
    reg [1:0] start, portSel;
    reg [2:0] currTime = 3'b000;
	 parameter sendData = 1'b1, checkSpacer = 1'b0;
	 reg [1:0] present_state = checkSpacer;
	 reg [1:0] isValid;
    
    always @ (posedge clk or posedge rst) begin
        seq <= seq >> 1;
        seq[8] <= serial_in;
        if (rst == 1'b1)
            seq <= 9'b100000000;
        else
				if (seq[8] == 1 & currTime == 3'b110 & start == 1)
                        start <= 0;
                else
                    if (seq[8] == 1 & seq[7] == 0)
								start <= 1;
    end
    
    /* Counter */
    
    always @ (posedge clk) begin
            if (rst == 1)
                    currTime <= 3'b000;
                else

                    if (currTime == 3'b110) begin
                        currTime <= 3'b000;
								
                    end
                        else
                            currTime <= currTime + 1'b1;
									 
				if (currTime == 3'b110 & start != 0) begin
					if (seq[6] == 0 & seq[7] == 0)
						portSel <= 2'b00;
					else
					if (seq[6] == 0 & seq[7] == 1)
						portSel <= 2'b01;
					else
					if (seq[6] == 1 & seq[7] == 0)
						portSel <= 2'b10;
					else
					if (seq[6] == 1 & seq[7] == 1)
						portSel <= 2'b11;
				end
									

    end

	 
	always @ (posedge clk) begin
		
	
	
		case (present_state)
			sendData: if (currTime == 3'b101) present_state <= checkSpacer;
							else present_state <= sendData;
			checkSpacer: if (seq[8] == 0 & currTime == 3'b110 & start == 1) present_state <= sendData;
								else present_state <= checkSpacer;
		endcase
			
	end
		
// & currTime == 3'b110
             
            assign port0 = (present_state == sendData & portSel == 2'b00) ? serial_in:1;
            assign port1 = (present_state == sendData & portSel == 2'b01) ? serial_in:1;
            assign port2 = (present_state == sendData & portSel == 2'b10) ? serial_in:1;
            assign port3 = (present_state == sendData & portSel == 2'b11) ? serial_in:1;
            
            assign valid = (portSel == 2'b00 ^ portSel == 2'b01 ^ portSel == 2'b10 ^ portSel == 2'b11) ? 1:0;

endmodule


module serial_com_test;
	reg serial_in, clk, rst;
	wire valid, port0, port1, port2, port3;
	
	serial_com uut (serial_in, clk, rst, valid, port0, port1, port2, port3);
	
	initial begin
	
	clk = 1'b0; rst = 1'b1; serial_in = 1'b1;
	end
	
	initial #5 rst = 1'b0;
	always #30 clk = ~clk;
	always #21 serial_in = ~serial_in;
//	initial serial_in = 1;
//	
//	initial #500 serial_in = 0;
//	always serial_in = 1;
endmodule
