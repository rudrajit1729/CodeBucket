`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:47:25 03/09/2020
// Design Name:   excesstobinary
// Module Name:   D:/SUBHANKAR_VERILOG/v1/excesstobinary_test.v
// Project Name:  v1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: excesstobinary
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module excesstobinary_test;

	// Inputs
	reg [3:0] X;

	// Outputs
	wire [3:0] B;

	// Instantiate the Unit Under Test (UUT)
	excesstobinary uut (
		.X(X), 
		.B(B)
	);
	integer i;
	initial begin
		// Initialize Inputs
		X = 0;

		// Wait 100 ns for global reset to finish
		#100;
       for(i=0;i<16;i=i+1) begin
			X=X+1;
			#100;
			end
		// Add stimulus here

	end
      
endmodule

