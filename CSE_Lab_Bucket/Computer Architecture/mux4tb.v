// Test-bench for the 4:1 multiplexer, ie mux4.v

`timescale 1ns / 1ps

module mux4tb;

	// Inputs
	reg [1:0] S;
	reg [3:0] I;
	reg E;	
	wire Y;
	// Instantiate the Unit Under Test (UUT)
	mux4 uut (
		.S(S), 
		.I(I), 
		.E(E), 
		.Y(Y)
	);
	integer i;
	initial begin
		// Initialize Inputs
		
		S = 0;
		E = 1;
		I = 4'b1001;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		for(i = 0; i < 4; i = i + 1)begin
			E = 0;
			S = S + 1;
			#100;
		end

	end
      

endmodule

