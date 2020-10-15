`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:33:46 04/05/2020
// Design Name:   decrementer
// Module Name:   D:/SUBHANKAR_VERILOG/v1/decrementer_test.v
// Project Name:  v1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: decrementer
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module decrementer_test;

	// Inputs
	reg [3:0] X;

	// Outputs
	wire [3:0] S;
	wire [3:0] Co;

	// Instantiate the Unit Under Test (UUT)
	decrementer uut (
		.X(X), 
		.S(S), 
		.Co(Co)
	);

	initial begin
		// Initialize Inputs
		X = 3;

		// Wait 100 ns for global reset to finish
		#100;
		X=5;
		#100;
		X=8;
		#100;
		X=10;
		#100;
        
		// Add stimulus here

	end
      
endmodule

