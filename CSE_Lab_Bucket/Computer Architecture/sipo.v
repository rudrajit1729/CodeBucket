`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    04:50:08 10/07/2020 
// Design Name: 
// Module Name:    sipo 
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
module sipo(
    input in,
    input clk,
    output reg [3:0] out
    );

	initial
		out = 0;
	always@ (negedge clk) begin
		out = out >> 1;
		out[3] = in;
	end

endmodule
