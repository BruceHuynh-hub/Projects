module firstAndLastTo7seg1(input [15:0] dataInput, output [6:0] segOut1, segOut2, segOut3, segOut4);
	reg [6:0] seg1, seg2, seg3, seg4;
	always @(*)
		 begin


				case (dataInput[15:12]) //case statement
					4'b0000 : seg1 = 7'b1000000;  // 0
					4'b0001 : seg1 = 7'b1111001;  // 1 
					4'b0010 : seg1 = 7'b0100100;  // 2
					4'b0011 : seg1 = 7'b0110000;  // 3
					4'b0100 : seg1 = 7'b0011001;  // 4
					4'b0101 : seg1 = 7'b0010010;  // 5
					4'b0110 : seg1 = 7'b0000010;  // 6
					4'b0111 : seg1 = 7'b1111000;  // 7
					4'b1000 : seg1 = 7'b0000000;  // 8
					4'b1001 : seg1 = 7'b0010000;  // 9
					4'b1010 : seg1 = 7'b0001000;  // A
					4'b1011 : seg1 = 7'b0000011;  // B
					4'b1100 : seg1 = 7'b1000110;  // C
					4'b1101 : seg1 = 7'b0100001;  // D
					4'b1110 : seg1 = 7'b0000110;  // E
					4'b1111 : seg1 = 7'b0001110;  // F
					default : seg1 = 7'b1000000;  // zero
				endcase
				
				case (dataInput[11:8]) //case statement
					4'b0000 : seg2 = 7'b1000000;  // 0
					4'b0001 : seg2 = 7'b1111001;  // 1 
					4'b0010 : seg2 = 7'b0100100;  // 2
					4'b0011 : seg2 = 7'b0110000;  // 3
					4'b0100 : seg2 = 7'b0011001;  // 4
					4'b0101 : seg2 = 7'b0010010;  // 5
					4'b0110 : seg2 = 7'b0000010;  // 6
					4'b0111 : seg2 = 7'b1111000;  // 7
					4'b1000 : seg2 = 7'b0000000;  // 8
					4'b1001 : seg2 = 7'b0010000;  // 9
					4'b1010 : seg2 = 7'b0001000;  // A
					4'b1011 : seg2 = 7'b0000011;  // B
					4'b1100 : seg2 = 7'b1000110;  // C
					4'b1101 : seg2 = 7'b0100001;  // D
					4'b1110 : seg2 = 7'b0000110;  // E
					4'b1111 : seg2 = 7'b0001110;  // F
					default : seg2 = 7'b1000000;  // zero
				endcase		
				
				case (dataInput[7:4]) //case statement
					4'b0000 : seg3 = 7'b1000000;  // 0
					4'b0001 : seg3 = 7'b1111001;  // 1 
					4'b0010 : seg3 = 7'b0100100;  // 2
					4'b0011 : seg3 = 7'b0110000;  // 3
					4'b0100 : seg3 = 7'b0011001;  // 4
					4'b0101 : seg3 = 7'b0010010;  // 5
					4'b0110 : seg3 = 7'b0000010;  // 6
					4'b0111 : seg3 = 7'b1111000;  // 7
					4'b1000 : seg3 = 7'b0000000;  // 8
					4'b1001 : seg3 = 7'b0010000;  // 9
					4'b1010 : seg3 = 7'b0001000;  // A
					4'b1011 : seg3 = 7'b0000011;  // B
					4'b1100 : seg3 = 7'b1000110;  // C
					4'b1101 : seg3 = 7'b0100001;  // D
					4'b1110 : seg3 = 7'b0000110;  // E
					4'b1111 : seg3 = 7'b0001110;  // F
					default : seg3 = 7'b1000000;  // zero
				endcase		
				
				case (dataInput[3:0]) //case statement
					4'b0000 : seg4 = 7'b1000000;  // 0
					4'b0001 : seg4 = 7'b1111001;  // 1 
					4'b0010 : seg4 = 7'b0100100;  // 2
					4'b0011 : seg4 = 7'b0110000;  // 3
					4'b0100 : seg4 = 7'b0011001;  // 4
					4'b0101 : seg4 = 7'b0010010;  // 5
					4'b0110 : seg4 = 7'b0000010;  // 6
					4'b0111 : seg4 = 7'b1111000;  // 7
					4'b1000 : seg4 = 7'b0000000;  // 8
					4'b1001 : seg4 = 7'b0010000;  // 9
					4'b1010 : seg4 = 7'b0001000;  // A
					4'b1011 : seg4 = 7'b0000011;  // B
					4'b1100 : seg4 = 7'b1000110;  // C
					4'b1101 : seg4 = 7'b0100001;  // D
					4'b1110 : seg4 = 7'b1111001;  // E
					4'b1111 : seg4 = 7'b0001110;  // F
					default : seg4 = 7'b1000000;  // zero
			  endcase
			  		  

		 end

			
		assign segOut1 = seg1; 
		assign segOut2 = seg2; 
		assign segOut3 = seg3; 
		assign segOut4 = seg4; 
 


endmodule
