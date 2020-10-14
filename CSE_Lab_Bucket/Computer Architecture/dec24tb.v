// Test-bench for the 2:4 decoder, ie, dec24.v

`timescale 1ns / 1ps

module dec24tb;

	// Inputs
	reg [1:0] I;

	// Outputs
	wire [3:0] Q;

	// Instantiate the Unit Under Test (UUT)
	dec24 uut (
		.I(I), 
		.Q(Q)
	);

	initial begin
		// Initialize Inputs
		I = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		repeat(3) begin
			I = I + 1;
			#100;
		end

	end
      
endmodule

