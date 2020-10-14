`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:41:55 03/09/2020
// Design Name:   binarytogrey
// Module Name:   D:/SUBHANKAR_VERILOG/v1/binarytogrey_test.v
// Project Name:  v1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: binarytogrey
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module binarytogrey_test;

	// Inputs
	reg [3:0] BIN;

	// Outputs
	wire [3:0] G;

	// Instantiate the Unit Under Test (UUT)
	binarytogrey uut (
		.BIN(BIN), 
		.G(G)
	);
	integer i;
	initial begin
		// Initialize Inputs
		BIN = 0;

		// Wait 100 ns for global reset to finish
		#100;
        for(i=0;i<16;i=i+1) begin
				BIN=BIN+1;
				#100;
				end
		// Add stimulus here

	end
      
endmodule

