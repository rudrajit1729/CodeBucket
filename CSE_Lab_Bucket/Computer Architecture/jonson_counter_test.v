`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:35:47 04/20/2020
// Design Name:   jonson_counter
// Module Name:   D:/SUBHANKAR_VERILOG/v1/jonson_counter_test.v
// Project Name:  v1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: jonson_counter
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module jonson_counter_test;

	// Inputs
	reg clk;
	reg clr;

	// Outputs
	wire [3:0] q;

	// Instantiate the Unit Under Test (UUT)
	jonson_counter uut (
		.q(q), 
		.clk(clk), 
		.clr(clr)
	);

	initial begin
		clr=1'b0;
        #50 clr=1'b1;
        #100 clr=1'b0;
	end
	always 
            begin
            #50 clk=1'b1;
            #50 clk=1'b0;
            end
      
endmodule

