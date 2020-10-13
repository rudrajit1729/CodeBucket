// Test-bench for the 4x4 RAM16, ie, RAM16.v

`timescale 1ns / 1ps

module RAMtb;

	// Inputs
	reg WE;
	reg EN;
	reg [1:0] A;
	reg [3:0] D;

	// Outputs
	wire [3:0] Q;

	// Instantiate the Unit Under Test (UUT)
	RAM16 uut (
		.WE(WE), 
		.EN(EN), 
		.A(A), 
		.D(D), 
		.Q(Q)
	);

	initial begin
		// Initialize Inputs
		WE = 0;
		EN = 0;
		A = 0;
		D = 0;

		// Wait 100 ns for global reset to finish
		#200;
      repeat(3)
		begin
			A = A + 1;
			#20;
			D = D + 1;
			#100;
		end
		WE = 1;
		A = 0;
		#100;
		repeat(3)
		begin
			A = A + 1;
			D = A - 1;
			#100;
		end
		EN = 1;
		#100;	

	end
      
endmodule

