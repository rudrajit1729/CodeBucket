`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:57:47 04/21/2020 
// Design Name: 
// Module Name:    updown_counter 
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
module updown_counter(
    input Clk,
    input reset,
    input UpOrDown,
    output [3:0] Count
    );

	reg [3 : 0] Count = 0;  
    
     always @(posedge(Clk) or posedge(reset))
     begin
        if(reset == 1) 
            Count <= 0;
        else    
            if(UpOrDown == 1)   
                if(Count == 15)
                    Count <= 0;
                else
                    Count <= Count + 1; 
            else  
                if(Count == 0)
                    Count <= 15;
                else
                    Count <= Count - 1; 
     end    
endmodule
