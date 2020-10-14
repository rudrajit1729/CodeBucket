`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    04:42:12 10/07/2020 
// Design Name: 
// Module Name:    siso 
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
module siso(
    input in,
    input clk,
    output reg out
    );

	reg [3:0] q;
	initial
		q = 0;
	always@ (negedge clk) begin
		q[3] = in;
		q = q >> 1;
		out = q[0];
	end

endmodule
