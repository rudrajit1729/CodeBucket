module BinaryToBCD(a,b);
input [3:0]a;
output [4:0]b;
reg [4:0]r;
always@(a)
if(a>9)
r=a+6;
else
r=a;
assign b=r;
endmodule

