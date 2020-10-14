`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:57:21 04/27/2020 
// Design Name: 
// Module Name:    GPR 
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
module BasicCell(q,CLR,CLK,s,A);
	output q;
	input CLK,CLR;
	input [1:0] s;
	input [3:0] A;
	wire data, q_bar;
	mux4to1 M1(data,s,A);
	D_ff D0(q,q_bar,CLR,CLK,data);
endmodule
module mux4to1(X, s, A);
	output X;
	input [1:0] s;
	input [3:0] A;
	assign X = (s == 2'b00)? A[0]:
				  (s == 2'b01)? A[1]:
				  (s == 2'b10)? A[1]: A[3];
endmodule
module GPR(
    input CLR,
    input CLK,
    input r_in,
    input l_in,
    input [1:0] S,
    input [3:0] X,
    output [3:0] Q
    );	
	wire [3:0] A;
	BasicCell Cell3 (A[3] , CLR , CLK , S , {X[3] , A[2] , r_in , A[3]}); 
	BasicCell Cell2 (A[2] , CLR , CLK , S , {X[2] , A[1] , A[3] , A[2]});
	BasicCell Cell1 (A[1] , CLR , CLK , S , {X[1] , A[0] , A[2] , A[1]});
	BasicCell Cell0 (A[0] , CLR , CLK , S , {X[0] , l_in , A[1] , A[0]});
	assign Q = A;
endmodule
