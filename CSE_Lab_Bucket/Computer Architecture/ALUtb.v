//Test Bench for ALU

`timescale 1ns / 1ps


module alutb;

	// Inputs
	reg [7:0] A;
	reg [7:0] B;
	reg Ci;
	reg [2:0] S;

	// Outputs
	wire [8:0] O;

	// Instantiate the Unit Under Test (UUT)
	alu uut (
		.A(A), 
		.B(B), 
		.Ci(Ci), 
		.S(S), 
		.O(O)
	);

	initial begin
		// Initialize Inputs
		A = 8'b10001100; B = 8'b00010011;Ci = 1;S = 0; #100;
		 S=1;#100; S=2;#100; S=3;#100; S=4;#100; S=5;#100; S=6;#100; S=7;#100;
		
	end
      
endmodule

