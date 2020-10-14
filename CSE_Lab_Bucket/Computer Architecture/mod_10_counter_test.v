`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   18:27:38 04/20/2020
// Design Name:   mod_10_counter
// Module Name:   D:/SUBHANKAR_VERILOG/v1/mod_10_counter_test.v
// Project Name:  v1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: mod_10_counter
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module mod_10_counter_test;

	// Inputs
	reg clk;
	reg rst;
	reg enable;

	// Outputs
	wire [3:0] counter_output;

	// Instantiate the Unit Under Test (UUT)
	mod_10_counter uut (
		.clk(clk), 
		.rst(rst), 
		.enable(enable), 
		.counter_output(counter_output)
	);

	always
#50 clk= ~ clk;

initial begin
clk=0;
// Initialize Inputs
rst = 0;
enable = 0;
#100;
rst=0;
enable=1;
#100;
rst=0;
enable=1;


// Wait 100 ns for global reset to finish
#100;
end
      
endmodule

