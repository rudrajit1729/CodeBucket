`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   04:56:15 10/07/2020
// Design Name:   piso
// Module Name:   F:/Xilinx/pisotb.v
// Project Name:  Xilinx
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: piso
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module pisotb;

	// Inputs
	reg [3:0] in;
	reg mode;
	reg clk;

	// Outputs
	wire out;

	// Instantiate the Unit Under Test (UUT)
	piso uut (
		.in(in), 
		.mode(mode), 
		.clk(clk), 
		.out(out)
	);

	initial begin
		// Initialize Inputs
		in = 0;
		mode = 0;
		clk = 0;

		// Wait 100 ns for global reset to finish
		#50;
		in = 4'b1011; mode = 1; clk = 1; #50;
		in = 4'b1011; mode = 1; clk = 0; #50;
		in = 4'b0101; mode = 0;
		repeat(4) begin
			clk = 1; #50;
			clk = 0; #50;
		end
        
		// Add stimulus here

	end
      
endmodule

