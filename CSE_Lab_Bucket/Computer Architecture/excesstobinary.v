`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:44:22 03/09/2020 
// Design Name: 
// Module Name:    excesstobinary 
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
module excesstobinary(
    input [3:0] X,
    output [3:0] B
    );
	reg [3:0] B;
	
	always@(X) begin
		B[3]=(X[3]&X[1]&X[0])|(X[3]&X[2]);
		B[2]=(X[2]&X[1]&X[0])|((~X[2])&(~X[1]))|((~X[2])&(~X[0]));
		B[1]=((~X[3])&(~X[1])&(~X[0]))|((~X[2])&(~X[1])&X[0])|((~X[3])&X[1]&(~X[0]))|((~X[2])&X[1]&(~X[0]));
		B[0]=~X[0];
		 end
		

endmodule
