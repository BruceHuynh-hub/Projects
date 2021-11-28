module firstAndLastTo7Seg(input clk, input [3:0] arrayFirst, arrayLast, output [6:0] Seg7first, Seg7last);
	reg [6:0] seg1, segL;
	always @(posedge clk)
		 begin
			  case (arrayFirst) //case statement
					4'b0000 : seg1 = 7'b1000000;
					4'b0001 : seg1 = 7'b1111001;
					4'b0010 : seg1 = 7'b0100100;
					4'b0011 : seg1 = 7'b0110000;
					4'b0100 : seg1 = 7'b0011001;
					4'b0101 : seg1 = 7'b0010010;
					4'b0110 : seg1 = 7'b0000010;
					4'b0111 : seg1 = 7'b1111000;
					4'b1000 : seg1 = 7'b0000000;
					4'b1001 : seg1 = 7'b0010000;
					default : seg1 = 7'b1111111; 
			  endcase
			  
			  	case (arrayLast) //case statement
					4'b0000 : segL = 7'b1000000;
					4'b0001 : segL = 7'b1111001;
					4'b0010 : segL = 7'b0100100;
					4'b0011 : segL = 7'b0110000;
					4'b0100 : segL = 7'b0011001;
					4'b0101 : segL = 7'b0010010;
					4'b0110 : segL = 7'b0000010;
					4'b0111 : segL = 7'b1111000;
					4'b1000 : segL = 7'b0000000;
					4'b1001 : segL = 7'b0010000;
					default : segL = 7'b1111111; 
			  endcase
		 end

		 assign Seg7first = seg1;
		 assign Seg7last = segL;

		 

endmodule
