`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:28:27 04/05/2020 
// Design Name: 
// Module Name:    decrementer 
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

module decrementer(
    input [3:0] X,
    output [3:0] S,
    output [3:0] Co
    );
		wire w1, w2, w3;
 fulladder u1(X[0], 1'b1, 1'b0, S[0], w1);
 fulladder u2(X[1], 1'b1, w1, S[1], w2);
 fulladder u3(X[2], 1'b1, w2, S[2], w3);
 fulladder u4(X[3], 1'b1, w3, S[3], Co);

endmodule
