// A 4-bit Carry-Lookahead-Adder

`timescale 1ns / 1ps

module CLA(
    input [3:0] A,
    input [3:0] B,
    input Cin,
    output [3:0] S,
    output Cout
    );
	 wire c1, c2, c3, c4;
	 assign S[0] = A[0] ^ B[0] ^ Cin;
	 assign S[1] = A[1] ^ B[1] ^ c1;
	 assign S[2] = A[2] ^ B[2] ^ c2;
	 assign S[3] = A[3] ^ B[3] ^ c3;
	 
	 assign c1 = (A[0] & B[0]) | (A[0] ^ B[0]) & Cin; //G0 + P0Cin
	 assign c2 = (A[1] & B[1]) | ((A[1] ^ B[1]) & (A[0] & B[0])) | ((A[1] ^ B[1]) & (A[0] ^ B[0]) & Cin);
	 assign c3 = (A[2] & B[2]) | ((A[2] ^ B[2]) & (A[1] & B[1])) | ((A[2] ^ B[2]) & (A[1] ^ B[1]) & (A[0] & B[0])) | ((A[2] ^ B[2]) & (A[1] ^ B[1]) & (A[0] ^ B[0]) & Cin);
	 assign c4 = (A[3] & B[3]) | (A[3] ^ B[3]) & (A[2] & B[2]) | (A[3] ^ B[3]) & (A[2] ^ B[2]) & (A[1] & B[1])| (A[3] ^ B[3]) & (A[2] ^ B[2]) & (A[1] ^ B[1]) & (A[0] & B[0]) | (A[3] ^ B[3]) & (A[2] ^ B[2]) & (A[1] ^ B[1]) & (A[0] & B[0]) & Cin;
	 
	assign Cout = c4;
	 

endmodule
