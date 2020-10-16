`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:29:54 04/09/2020
// Design Name:   Dflipflop
// Module Name:   D:/SUBHANKAR_VERILOG/v1/Dflipflop_test.v
// Project Name:  v1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Dflipflop
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Dflipflop_test;

	// Inputs
	reg d;
	reg clk;

	// Outputs
	wire q;
	wire qbar;

	// Instantiate the Unit Under Test (UUT)
	Dflipflop uut (
		.d(d), 
		.clk(clk), 
		.q(q), 
		.qbar(qbar)
	);

	initial begin
		d = 0;
		clk = 1;
		#100;
      d=0;
		clk=0;
		#100;
		d=1;
		clk=1;
		#100;
		d=1;
		clk=0;
		#100;

	end
      
endmodule

