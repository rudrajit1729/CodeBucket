//Test-bench for the asynchronous PIPO, ie, PIPO_async.v

`timescale 1ns / 1ps

module PIPO_async_tb;

	// Inputs
	reg [3:0] D;
	reg E;

	// Outputs
	wire [3:0] Q;

	// Instantiate the Unit Under Test (UUT)
	PIPO_async uut (
		.D(D), 
		.E(E), 
		.Q(Q)
	);

	initial begin
		// Initialize Inputs
		D = 0;
		E = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		repeat(15) begin
			D = D + 1;
			#100;
		end
		E = 1;
		#10;
		D = 3;

	end
      
endmodule

