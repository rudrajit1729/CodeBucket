`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   04:44:27 10/07/2020
// Design Name:   siso
// Module Name:   F:/Xilinx/sisotb.v
// Project Name:  Xilinx
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: siso
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module sisotb;

	// Inputs
	reg in;
	reg clk;

	// Outputs
	wire out;

	// Instantiate the Unit Under Test (UUT)
	siso uut (
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
		in = 0;
		repeat(4) begin
			clk = 1; #50;
			clk = 0; #50;
		end
        
		// Add stimulus here

	end
      
endmodule

