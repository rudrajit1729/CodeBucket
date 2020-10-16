module sipo_tb;
reg clk;
reg clear;
reg si;
wire [3:0] po;
sipo out (.clk(clk),.clear(clear),.si(si),.po(po) );
initial begin
clk = 0;
clear = 0;
si = 0;
#5 clear=1'b1;
#5 clear=1'b0;
#10 si=1'b1;
#10 si=1'b0;
#10 si=1'b0;
#10 si=1'b1;
#10 si=1'b0;
#10 si=1'bx;
end
always #5 clk = ~clk;
endmodule
