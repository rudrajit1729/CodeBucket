`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:38:35 03/09/2020 
// Design Name: 
// Module Name:    binarytogrey 
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
module binarytogrey(
    input [3:0] BIN,
    output [3:0] G
    );
	reg [3:0] G;
	
	always@(BIN) begin
		G[3]=BIN[3];
		G[2]=BIN[3]^BIN[2];
		G[1]=BIN[2]^BIN[1];
		G[0]=BIN[1]^BIN[0];
	end		

endmodule
