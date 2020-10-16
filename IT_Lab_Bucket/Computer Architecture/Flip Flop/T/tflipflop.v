module Tflipflop(t,clk,Q);
input t,clk;
output reg Q;
always@(posedge clk)
begin
if(t==1)
begin
Q <= !Q;
end
else 
begin
Q <= Q;
end
end
endmodule

