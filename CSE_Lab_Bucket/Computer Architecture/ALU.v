//8-bit ALU performing below 8 functions

`timescale 1ns / 1ps

module alu(
    input [7:0] A,
    input [7:0] B,
    input Ci,
    input [2:0] S,
    output reg[8:0] O
    );
always @(A,B,Ci,S,O)
	case(S)
		0:	O=A-B;
		1: O=A+B;
		2: O=A+B+Ci;
		3: O=A+B+(~Ci);
		4: O=A^B;
		5: O=~B;
		6: O=A|B;
		7: O=A&B;
	endcase
endmodule
