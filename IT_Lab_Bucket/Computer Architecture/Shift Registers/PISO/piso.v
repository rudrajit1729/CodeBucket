module piso(clk,rst,pi,so);
input clk,rst;
input [3:0]pi;
output so;
reg so;
reg [3:0]tmp;
always@(posedge clk,posedge rst)
begin
if(rst==1'b1)
begin
so<=1'b0;
tmp<=pi;
end
else
begin
so<=tmp[0];
tmp <= tmp>>1;
end
end
endmodule
