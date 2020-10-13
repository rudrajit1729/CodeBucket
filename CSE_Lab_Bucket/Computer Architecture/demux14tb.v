// Test-bench for the 1:4 demultiplexer

`timescale 1ns / 1ps

module demux14tb;

	// Inputs
	reg I;
	reg [1:0] S;

	// Outputs
	wire [3:0] Y;

	// Instantiate the Unit Under Test (UUT)
	demux14 uut (
		.I(I), 
		.S(S), 
		.Y(Y)
	);

	initial begin
		// Initialize Inputs
		I = 0;
		S = 0;

		// Wait 100 ns for global reset to finish
		#100;
		I = 1;
		#100;
		repeat(3) begin
			S = S + 1;
			#100;
		end
	end      
endmodule

