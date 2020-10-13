// A 2:4 decoder. I denotes the input lines, and Q is the output

`timescale 1ns / 1ps

module dec24(
    input [1:0] I,
    output [3:0] Q
    );
	 assign Q[0] = ~I[0] & ~I[1];
	 assign Q[1] = I[0] & ~I[1];
	 assign Q[2] = ~I[0] & I[1];
	 assign Q[3] = I[0] & I[1];


endmodule
