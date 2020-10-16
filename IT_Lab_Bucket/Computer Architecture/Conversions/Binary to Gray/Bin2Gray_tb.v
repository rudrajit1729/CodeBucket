module Bin2Gray_tb;
reg [3:0]t_a;
wire [3:0]t_b;
Binary2Gray my_gate(.a(t_a),.b(t_b));
initial
begin
$monitor(t_a,t_b);
t_a=4'b0000;
#100
t_a=4'b0110;
#100
t_a=4'b1010;
#100
t_a=4'b1100;
end
endmodule


