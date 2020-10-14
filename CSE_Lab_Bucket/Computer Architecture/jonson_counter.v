`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:28:51 04/20/2020 
// Design Name: 
// Module Name:    jonson_counter 
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
module jonson_counter(q,clk,clr);
    input clk;
    input clr;
    output [3:0] q;
    reg [3:0]q;
  always @(posedge clk)
       if(clr==1)
            q<=4'b1000;
        else
            begin
                q[3]<=q[2];
                q[2]<=q[1];
                q[1]<=q[0];
                q[0]<=(~q[3]);
            end

endmodule
