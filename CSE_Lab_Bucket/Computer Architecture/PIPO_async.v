// An asynchronous 4-bit Parallel-In-Parallel-Out register. Mainly useful as a building block for RAM

`timescale 1ns / 1ps

module PIPO_async(
    input [3:0] D,
    input E, // active-low enable
    output [3:0] Q
    );
	reg [3:0]data;
	assign Q = data;
	always@(D or E) begin
		if(~E)
			data = D;
	end

endmodule
