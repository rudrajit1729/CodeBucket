module AddSub4Bit(a,b,c,result,cout);
input [3:0]a,b;
input c;
output [3:0]result;
output cout;
reg [4:0]r;
always@(a,b)
if(a>b)
r=(c==0)?(a+b):(a-b);
else
r=(c==0)?(a+b):(b-a);
assign result=r[3:0];
assign cout=r[4];
endmodule

