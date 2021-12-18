module demux (input sel, input [3:0] inBus, output [3:0] out0, out1);

	assign out0 = (sel == 0) ? inBus : 0;
	assign out1 = (sel == 1) ? inBus : 0;

endmodule
