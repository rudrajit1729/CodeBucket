// A 16-bit 4x4 RAM

`timescale 1ns / 1ps

module RAM16(
    input WE, // R/W - 0 to write and 1 to read
    input EN, // Chip select
    input [1:0] A, //4 words of 4 bits each
    input [3:0] D,
    output [3:0] Q
    );
	 
	 wire [3:0]rwbusdx;
	 wire [3:0]rwbusdc;
	 wire [3:0]rwbus;
	 
	 wire [3:0]data0out;
	 wire [3:0]data1out;
	 wire [3:0]data2out;
	 wire [3:0]data3out;
	 	 
		 
	xnor g1(rwbus[0], rwbusdc[0], rwbusdx[0]);
	xnor g2(rwbus[1], rwbusdc[1], rwbusdx[1]);
	xnor g3(rwbus[2], rwbusdc[2], rwbusdx[2]);
	xnor g4(rwbus[3], rwbusdc[3], rwbusdx[3]);
	
	demux14 rwmap(.I(WE), .S(A), .Y(rwbusdx));
	dec24 mask(.I(A), .Q(rwbusdc));
		
	mux4 out0(.I({data3out[0], data2out[0], data1out[0], data0out[0]}), .E(EN), .S(A), .Y(Q[0]));
	mux4 out1(.I({data3out[1], data2out[1], data1out[1], data0out[1]}), .E(EN), .S(A), .Y(Q[1]));
	mux4 out2(.I({data3out[2], data2out[2], data1out[2], data0out[2]}), .E(EN), .S(A), .Y(Q[2]));
	mux4 out3(.I({data3out[3], data2out[3], data1out[3], data0out[3]}), .E(EN), .S(A), .Y(Q[3]));
	
	PIPO_async w1(.D(D), .E(EN | rwbus[0]), .Q(data0out));
	PIPO_async w2(.D(D), .E(EN | rwbus[1]), .Q(data1out));
	PIPO_async w3(.D(D), .E(EN | rwbus[2]), .Q(data2out));
	PIPO_async w4(.D(D), .E(EN | rwbus[3]), .Q(data3out));
	

endmodule
