// A 1:4 demultiplexer

`timescale 1ns / 1ps

module demux14(
    input I,
    input [1:0] S,
    output [3:0] Y
    );
	assign Y[0] = ~S[0] & ~S[1] & I;
	assign Y[1] = S[0] & ~S[1] & I;
	assign Y[2] = ~S[0] & S[1] & I;
	assign Y[3] = S[0] & S[1] & I;

endmodule
