module  JK_tb;
reg  j,k,clk;
always  #20 clk = ~clk;
JKflipflop  jk(.j(j),.k(k),.clk(clk),.Q(q));
initial  begin 
$monitor(j,k,q);
clk <= 1;
j <= 0;
k <= 0;
#20
j <= 0;
k <= 1;
#20
j <= 1;
k <= 0;
#20
j <= 1;
k <= 1;
end
endmodule

