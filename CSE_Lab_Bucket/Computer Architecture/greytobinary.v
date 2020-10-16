`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:53:12 03/09/2020 
// Design Name: 
// Module Name:    greytobinary 
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
module greytobinary(
    input [3:0] G,
    output [3:0] B
    );
	reg [3:0] B;
	
	always@(G) begin
		B[3]=G[3];
		B[2]=G[3]^G[2];
		B[1]=B[2]^G[1];
		B[0]=B[1]^G[0];
		
		end

endmodule
