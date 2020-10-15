`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:14:35 03/09/2020 
// Design Name: 
// Module Name:    binary_bcd 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module binary_bcd(
    input [3:0] BIN,
    output [4:0] BCD
    );
	reg [4:0] BCD;
	
	always@(BIN)begin
		BCD[4]=(BIN[3]&BIN[2])|(BIN[3]&BIN[1]);
		BCD[3]=BIN[3]&(~BIN[2])&(~BIN[1]);
		BCD[2]=((~BIN[3])&BIN[2])|(BIN[2]&BIN[1]);
		BCD[1]=(BIN[3]&BIN[2]&(~BIN[1]))|((~BIN[3])&BIN[1]);
		BCD[0]=BIN[0];
		end
	
endmodule
