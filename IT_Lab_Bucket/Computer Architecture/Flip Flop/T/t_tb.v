
module  T_tb;
reg  t , clk;
always  #20 clk = ~clk;
Tflipflop  x(.t(t),.clk(clk),.Q(q));
initial  begin 
$monitor(t,q);
clk <= 1;
t <= 0;
#20
t <=1;
#20
t <= 0;
#20
t <= 1;
end
endmodule
