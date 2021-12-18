module comparator(input [3:0] a, b, output equal, less, greater);

	assign less =  (a < b) ? 1:0;
	assign greater = (a > b) ? 1:0;
	assign equal = ((a + 1) == b) ? 1:0;
	

endmodule
