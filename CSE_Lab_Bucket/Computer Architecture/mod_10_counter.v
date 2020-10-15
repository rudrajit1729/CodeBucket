`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:21:38 04/20/2020 
// Design Name: 
// Module Name:    mod_10_counter 
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
module mod_10_counter(
    input clk,
    input rst,
    input enable,
    output reg [3:0] counter_output
    );
	always@ (posedge clk) begin 
		if( rst | counter_output==4'b1001)
			counter_output <= 4'b0000;
		else if(enable)
			counter_output <= counter_output + 1;
		else
			counter_output <= 0;
	end

endmodule
