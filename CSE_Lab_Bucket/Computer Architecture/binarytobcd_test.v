`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:19:29 03/09/2020
// Design Name:   binary_bcd
// Module Name:   D:/SUBHANKAR_VERILOG/v1/binarytobcd_test.v
// Project Name:  v1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: binary_bcd
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module binarytobcd_test;

	// Inputs
	reg [3:0] BIN;

	// Outputs
	wire [4:0] BCD;

	// Instantiate the Unit Under Test (UUT)
	binary_bcd uut (
		.BIN(BIN), 
		.BCD(BCD)
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

