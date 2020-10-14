// A 4:1 multiplexer, with active-low enable(E)

`timescale 1ns / 1ps

module mux4(
    input [1:0] S,
    input [3:0] I,
    input E,
    output reg Y
    );
	always@(E or S or I) begin
		Y = (~E) & ((~S[1] & ~S[0] & I[0]) | (~S[1] & S[0] & I[1]) | (S[1] & ~S[0] & I[2]) | (S[1] & S[0] & I[3]));
	end
	
endmodule


