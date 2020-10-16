`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:21:28 04/21/2020
// Design Name:   updown_counter
// Module Name:   D:/SUBHANKAR_VERILOG/v1/updown_counter_test.v
// Project Name:  v1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: updown_counter
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module updown_counter_test;

	// Inputs
	reg Clk;
	reg reset;
	reg UpOrDown;

	// Outputs
	wire [3:0] Count;

	// Instantiate the Unit Under Test (UUT)
	updown_counter uut (
		.Clk(Clk), 
		.reset(reset), 
		.UpOrDown(UpOrDown), 
		.Count(Count)
	);

	initial Clk = 0;
    always #50 Clk = ~Clk;
    
    initial begin
        // Apply Inputs
        reset = 0;
        UpOrDown = 0;
        #100;
        UpOrDown = 1;
      #100;
        reset = 1;
        UpOrDown = 0;
        #100;
        reset = 0;  
    end
      
      
endmodule

