module sipo(clk,clear, si, po);
input clk, si,clear;
output [3:0] po;
reg [3:0] tmp;
reg [3:0] po;

always @(posedge clk)
begin
if (clear)
tmp <= 4'b0000;
else
tmp <= tmp << 1;
tmp[0] <= si;
po = tmp;
end
endmodule
