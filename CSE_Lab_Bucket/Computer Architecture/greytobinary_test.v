`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:55:56 03/09/2020
// Design Name:   greytobinary
// Module Name:   D:/SUBHANKAR_VERILOG/v1/greytobinary_test.v
// Project Name:  v1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: greytobinary
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module greytobinary_test;

	// Inputs
	reg [3:0] G;

	// Outputs
	wire [3:0] B;

	// Instantiate the Unit Under Test (UUT)
	greytobinary uut (
		.G(G), 
		.B(B)
	);
	integer i;
	initial begin
		// Initialize Inputs
		G = 0;

		// Wait 100 ns for global reset to finish
		#100;
       for(i=0;i<16;i=i+1) begin
				G=G+1;
				#100;
				end
		// Add stimulus here

	end
      
endmodule

