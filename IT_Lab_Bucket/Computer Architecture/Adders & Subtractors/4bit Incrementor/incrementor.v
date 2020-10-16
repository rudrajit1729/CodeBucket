module incre4bit(a,b,cout);
input [3:0]a;
output [3:0]b;
output cout;
reg [4:0]r;
always@(a)
r=a+1;
assign b[3:0]=r[3:0];
assign cout=r[4];
endmodule 

