module piso_tb;
reg clk;
reg rst;
reg [3:0] pi;
wire so;
piso out (.clk(clk),.rst(rst),.pi(pi),.so(so) );

initial
clk=1'b1;
always #10 clk=~clk;
initial begin
rst=1'b1; pi=4'b1101;
#30 rst=1'b0;
#20 rst=1'b1;
#20 rst=1'b0;
end
initial
#100 $stop;
     

endmodule
