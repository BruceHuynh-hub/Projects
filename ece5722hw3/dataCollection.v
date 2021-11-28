module ece5722hw3 (input write_IO, read_IO, get_data, clk, rst, input [15:0] data_in, input [15:0] data_in_DCD, output interrupt, output [15:0] data_read_out);

wire startWire;
wire acknowledgeWire;
wire [7:0] dataAddOutWire;
wire [7:0] outputToBufferWire;
wire write_BufferW;


	DCD DCDstart(.address(data_in_DCD), .write_IO(write_IO), .clk(clk), .rst(rst), .start_or_acknowledge_out(startWire));
	DCD DCDacknowledge(.address(data_in_DCD), .write_IO(write_IO), .clk(clk), .rst(rst), .start_or_acknowledge_out(acknowledgeWire));
	IO_interface myIOI(.get_data(get_data), .start(startWire), .acknowledged(acknowledgeWire), .clk(clk), .rst(rst), .data_read(data_in_DCD), .dataAddOut(dataAddOutWire), 
	.write_Buffer(write_BufferW), .interrupt(interrupt));
	addressDecoder myaddressDecoder(.get_data(get_data), .address(data_in), .read_IO(read_IO), .clk(clk), .outputToBuffer(outputToBufferWire));


assign data_read_out[15:0] = { dataAddOutWire[7:0],  outputToBufferWire[7:0]};

	

endmodule


module DCD (input [15:0] address, input write_IO, clk, rst, output start_or_acknowledge_out);

	reg start_or_acknowledge_out_state;

always @ (posedge clk) begin

//			if ((address == 16'h5000 | address == 16'h5001) & write_IO == 1)
			if ((address == 16'h5000 | address == 16'h5001) & write_IO)
				start_or_acknowledge_out_state <= 1;
			else
				start_or_acknowledge_out_state <= 0;

end

assign start_or_acknowledge_out = start_or_acknowledge_out_state;


endmodule



module IO_interface (input start, get_data, acknowledged, clk, rst, input [15:0] data_read, output interrupt, write_Buffer, output [7:0] dataAddOut);
	reg [7:0] counter = 0;
	reg [7:0] dataH;
	reg [7:0] dataL;
	reg sendToInterrupt;
	reg write_Buffer_On;
	
always @ (posedge clk or posedge rst) begin

	if (rst) begin
		counter <= 0;
		dataH <= 8'b00000000;
		write_Buffer_On <= 0;
		sendToInterrupt <= 0;
	end
	else if (acknowledged == 1 & start != 1)
		counter <= 0;
	else if (start) begin
			counter <= counter + 1'b1;
			if (counter != 8'b11111111) begin
				dataH <= data_read[15:8];
				write_Buffer_On <= 1;
			end
			else if (counter == 8'b11111111) begin
				write_Buffer_On <= 0;
				sendToInterrupt <= 1;
				counter <= 8'b11111111;
			end
				

			
		end
	end


assign interrupt = sendToInterrupt;
assign dataAddOut = dataH;
assign write_Buffer = write_Buffer_On;
 
		
endmodule







module addressDecoder (input read_IO, get_data, clk, input [15:0] address, output [7:0] outputToBuffer);
reg outState;
always @ (posedge clk) begin
	if ((address >= 16'h5500 & address <= 16'h55FF) & read_IO & get_data)
		outState <= 1;
	else
		outState <= 0;
end

assign outputToBuffer = (outState) ? address[7:0] : 8'h00;
		
		

endmodule

module ece5722hw3_tb ();

reg write_IO, read_IO, get_data, clk, rst;
reg [15:0] data_in;
reg [15:0] data_in_DCD;
wire [15:0] data_read_out;
wire interrupt;



ece5722hw3 UUT (.write_IO(write_IO), .read_IO(read_IO), .get_data(get_data), .clk(clk), .rst (rst), .data_in(data_in), .data_in_DCD(data_in_DCD),
.data_read_out(data_read_out), .interrupt(interrupt));



initial begin

data_in <= 16'h5505;
data_in_DCD <= 16'h5001;
get_data <= 0;
write_IO <= 1;
read_IO <= 1;
rst <= 1;
#5 rst <= 0;
clk <= 0;

end

always #30 data_in <= data_in + 1;
always #20 clk = ~clk;
always #25 get_data = ~get_data;


endmodule

 