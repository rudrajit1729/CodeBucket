//Test Bench for ROM cell

`timescale 1ns / 1ps

module romtb;

	// Inputs
	reg [1:0] A;
	reg E;

	// Outputs
	wire [3:0] Q;

	// Instantiate the Unit Under Test (UUT)
	rom uut (
		.A(A), 
		.E(E), 
		.Q(Q)
	);

	initial begin
		// Initialize Inputs
		A = 0;E = 0;#100;
      A=1;#100; A=2;#100;
		E=1;	A=3;#100;  E=0;
		// Add stimulus here

	end
      
endmodule

