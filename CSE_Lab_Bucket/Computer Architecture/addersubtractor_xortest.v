`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   13:39:46 03/30/2020
// Design Name:   addersubtractor_xor
// Module Name:   D:/SUBHANKAR_VERILOG/v1/addersubtractor_xortest.v
// Project Name:  v1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: addersubtractor_xor
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module addersubtractor_xortest;

	// Inputs
	reg [3:0] A;
	reg [3:0] B;
	reg Op;

	// Outputs
	wire [3:0] S;
	wire C;
	wire V;

	// Instantiate the Unit Under Test (UUT)
	addersubtractor_xor uut (
		.A(A), 
		.B(B), 
		.Op(Op), 
		.S(S), 
		.C(C), 
		.V(V)
	);

	initial begin
		// Initialize Inputs
		Op = 0;
		A = 7;
		B = 6;
		#100;
		Op =0;
		A=2;
		B=6;
		#100;
		Op=1;
		A=8;
		B=4;
		#100;
		Op = 1;
		A = 7;
		B = 6;
		#100;
		

		
	end
      
endmodule

