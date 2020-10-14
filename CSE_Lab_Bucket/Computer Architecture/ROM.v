//Verilog program to model a ROM memory cell

`timescale 1ns / 1ps

module rom( input [1:0]A, input E, output reg[3:0]Q );
always @(E,A,Q) begin
	if(E==0) 
			case(A)
				2'b00: Q=7;
				2'b01: Q=9;
				2'b10: Q=11;
				2'b11: Q=15;
			endcase
	if(E==1) 
		Q=4'bx;
	end
endmodule
