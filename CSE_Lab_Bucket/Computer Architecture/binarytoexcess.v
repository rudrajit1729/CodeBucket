`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:31:52 03/09/2020 
// Design Name: 
// Module Name:    binarytoexcess 
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
module binarytoexcess(
    input [3:0] B,
    output [3:0] X
    );
	reg [3:0] X;
	
	always@(B) begin
		X[3]=(B[2]&(B[0]|B[1]))|B[3];
		X[2]=((~B[2])&(B[0]|B[1]))|((~B[0])&(~B[1])&B[2]);
		X[1]=~(B[0]^B[1]);
		X[0]=~B[0];
		end

endmodule
