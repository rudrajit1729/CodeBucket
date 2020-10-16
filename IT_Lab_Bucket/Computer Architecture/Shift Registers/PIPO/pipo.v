module pipo(clk,clear, pi, po);
input clk,clear;
input [3:0] pi;
output [3:0] po;
wire [3:0] pi;
reg [3:0] po;

always @(posedge clk)
begin
if (clear)
po<= 4'b0000;
else
po <= pi;
end
endmodule
