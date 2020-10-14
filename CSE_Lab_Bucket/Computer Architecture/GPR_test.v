`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:18:45 04/27/2020
// Design Name:   GPR
// Module Name:   D:/SUBHANKAR_VERILOG/v1/GPR_test.v
// Project Name:  v1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: GPR
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module GPR_test;

	// Inputs
	reg CLR;
	reg CLK;
	reg r_in;
	reg l_in;
	reg [1:0] S;
	reg [3:0] X;

	// Outputs
	wire [3:0] Q;

	// Instantiate the Unit Under Test (UUT)
	GPR uut (
		.CLR(CLR), 
		.CLK(CLK), 
		.r_in(r_in), 
		.l_in(l_in), 
		.S(S), 
		.X(X), 
		.Q(Q)
	);

	initial begin
		// Initialize Inputs
		CLR = 0;
		CLK = 0;
		r_in = 0;
		l_in = 0;
		S = 0;
		X = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
      
endmodule

