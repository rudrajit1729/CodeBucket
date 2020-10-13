// Horizontal cascading using the 16-bit 4x4 RAM, ie, RAM16.v

`timescale 1ns / 1ps

module horzcasc(
    input WE,
    input EN,
    input [1:0] A,
    input [7:0] D,
    output [7:0] Q
    );
	RAM16 ram1(.EN(EN), .WE(WE), .A(A), .D(D[7:4]), .Q(Q[7:4]));
	RAM16 ram2(.EN(EN), .WE(WE), .A(A), .D(D[3:0]), .Q(Q[3:0]));
	

endmodule
