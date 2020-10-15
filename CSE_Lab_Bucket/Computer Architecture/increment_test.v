`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   07:17:36 04/01/2020
// Design Name:   incrementer
// Module Name:   D:/SUBHANKAR_VERILOG/v1/increment_test.v
// Project Name:  v1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: incrementer
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module increment_test;

	// Inputs
	reg [3:0] X;

	// Outputs
	wire [3:0] S;
	wire [3:0] Co;

	// Instantiate the Unit Under Test (UUT)
	incrementer uut (
		.X(X), 
		.S(S), 
		.Co(Co)
	);

	initial begin
		// Initialize Inputs
		X = 3;
		#100;
		X=5;
		#100;
		X=8;
		#100;
		X=10;
		#100;    
	end
      
endmodule

