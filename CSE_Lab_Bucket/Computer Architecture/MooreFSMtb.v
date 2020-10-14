//Test Bench of Moore FSM

`timescale 1ns / 1ps


module Mooretb;

	// Inputs
	reg a;
	reg clk;
	reg rst;

	// Outputs
	wire q;
	wire [3:0] current;

	// Instantiate the Unit Under Test (UUT)
	Moore uut (
		.a(a), 
		.clk(clk), 
		.rst(rst), 
		.q(q), 
		.current(current)
	);

	initial begin
	clk = 0;
	forever #50 clk=~clk;
	end 
	initial begin
		// Initialize Inputs
		a = 0;rst = 1;#100;
		rst=0;#100; a=1;#100; a=1;#100; a=0;#100;
		a=1;#100; a=1;#100; a=1;#100; a=0;#100;
	end
      
endmodule

