`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:21:23 04/09/2020 
// Design Name: 
// Module Name:    Dflipflop 
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


module Dflipflop(
    input d,
    input clk,
    output q,
    output qbar
    );

sr_flip_flop call (d,~d,clk,q,qbar);

endmodule
