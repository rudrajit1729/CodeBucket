`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:32:10 03/30/2020 
// Design Name: 
// Module Name:    addersubtractor_xor 
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
module addersubtractor_xor(
    input [3:0] A,
    input [3:0] B,
    input Op,
    output [3:0] S,
    output C,
    output V
    );
	wire 	C0; 
   wire 	C1; 
   wire 	C2; 
   wire 	C3; 
   
   wire 	B0; 
   wire 	B1; 
   wire 	B2; 
   wire 	B3; 
	
	xor(B0, B[0], Op);
   xor(B1, B[1], Op);
   xor(B2, B[2], Op);
   xor(B3, B[3], Op);
   xor(C, C3, Op);     
   xor(V, C3, C2);    
   
   full_adder fa0(S[0], C0, A[0], B0, Op);    
   full_adder fa1(S[1], C1, A[1], B1, C0);
   full_adder fa2(S[2], C2, A[2], B2, C1);
   full_adder fa3(S[3], C3, A[3], B3, C2);    
endmodule 


module full_adder(S, Cout, A, B, Cin);
   output S;
   output Cout;
   input  A;
   input  B;
   input  Cin;
   
   wire   w1;
   wire   w2;
   wire   w3;
   wire   w4;
   
   xor(w1, A, B);
   xor(S, Cin, w1);
   and(w2, A, B);   
   and(w3, A, Cin);
   and(w4, B, Cin);   
   or(Cout, w2, w3, w4);
endmodule


