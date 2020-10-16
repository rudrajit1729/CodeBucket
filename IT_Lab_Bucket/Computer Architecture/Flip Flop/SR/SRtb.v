module SR_tb;
reg s,r,clk;
always  #20 clk = ~clk;
SRflipflop  sr(.s(s),.r(r),.clk(clk),.Q(q));
initial begin 
$monitor(s,r,q);
clk <= 1;

s <= 0;
r <= 0;
#20
s <= 0;
r <= 1;
#20
s <= 1;
r <= 0;
#20
s <= 1;
r <= 1;
end
endmodule

