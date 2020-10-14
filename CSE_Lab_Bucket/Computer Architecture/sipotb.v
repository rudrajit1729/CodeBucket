`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   04:51:27 10/07/2020
// Design Name:   sipo
// Module Name:   F:/Xilinx/sipotb.v
// Project Name:  Xilinx
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: sipo
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module sipotb;

	// Inputs
	reg in;
	reg clk;

	// Outputs
	wire [3:0] out;

	// Instantiate the Unit Under Test (UUT)
	sipo uut (
		.in(in), 
		.clk(clk), 
		.out(out)
	);

	initial begin
		// Initialize Inputs
		in = 0;
		clk = 0;

		// Wait 100 ns for global reset to finish
		#50;
		in = 1; clk = 1; #50;
		in = 1; clk = 0; #50;
		in = 1; clk = 1; #50;
		in = 1; clk = 0; #50;
		in = 0; clk = 1; #50;
		in = 0; clk = 0; #50;
		in = 1; clk = 1; #50;
		in = 1; clk = 0; #50;
		in = 0; clk = 1; #50;
		in = 0; clk = 0; #50;
        
		// Add stimulus here

	end
      
endmodule

