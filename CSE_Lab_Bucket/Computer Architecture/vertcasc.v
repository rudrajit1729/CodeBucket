// Vertical cascading using the 16 bit 4x4 RAM, ie, RAM16.v

`timescale 1ns / 1ps

module vertcasc(
    input WE,
    input [2:0] A,
    input [3:0] D,
    output [3:0] Q
    );
	 wire [3:0] ram1out;
	 wire [3:0] ram2out;
	 
	RAM16 ram1(.EN(A[2]), .A(A[1:0]), .WE(WE), .D(D), .Q(ram1out));
	RAM16 ram2(.EN(~A[2]), .A(A[1:0]), .WE(WE), .D(D), .Q(ram2out));
	
	assign Q = ram1out | ram2out;

endmodule
