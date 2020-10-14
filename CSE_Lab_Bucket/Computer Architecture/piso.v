`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    04:54:15 10/07/2020 
// Design Name: 
// Module Name:    piso 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module piso(
    input [3:0] in,
    input mode,
    input clk,
    output reg out
    );

	reg [3:0] q;
	initial begin
		out = 0;
		q = 0;
	end
	always@ (negedge clk) begin
		if (mode)
			q = in;
		else begin
			out = q[0];
			q = q >> 1;
		end
	end

endmodule
