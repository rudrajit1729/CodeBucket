`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:34:44 03/09/2020
// Design Name:   binarytoexcess
// Module Name:   D:/SUBHANKAR_VERILOG/v1/binarytoexcess_test.v
// Project Name:  v1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: binarytoexcess
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module binarytoexcess_test;

	// Inputs
	reg [3:0] B;

	// Outputs
	wire [3:0] X;

	// Instantiate the Unit Under Test (UUT)
	binarytoexcess uut (
		.B(B), 
		.X(X)
	);
	integer i;
	initial begin
		// Initialize Inputs
		B = 0;

		// Wait 100 ns for global reset to finish
		#100;
		for(i=0;i<16;i=i+1) begin
			B=B+1;
			#100;
			end
        
		// Add stimulus here

	end
      
endmodule

