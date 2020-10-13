// Test-bench for the CLA. ie, CLA.v

`timescale 1ns / 1ps

module CLAtb;

	// Inputs
	reg [3:0] A;
	reg [3:0] B;
	reg Cin;

	// Outputs
	wire [3:0] S;
	wire Cout;

	// Instantiate the Unit Under Test (UUT)
	CLA uut (
		.A(A), 
		.B(B), 
		.Cin(Cin), 
		.S(S), 
		.Cout(Cout)
	);
	integer i;
	initial begin
		// Initialize Inputs
		A = 0;
		B = 0;
		Cin = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		B = 3;
		for(i = 1; i < 16; i = i + 1)
		begin
			A = i;
			#100;
		end
		

	end
      
endmodule
