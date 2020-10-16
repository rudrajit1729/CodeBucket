module HalfAdd_tb;
reg t_a,t_b;
wire t_sum,t_carry;
HalfAdd my_gate(.a(t_a),.b(t_b),.sum(t_sum),.carry(t_carry));
initial
begin
$monitor(t_a,t_b,t_sum,t_carry);
t_a=1'b0;
t_b=1'b0;
#100
t_a=1'b0;
t_b=1'b1;
#100
t_a=1'b1;
t_b=1'b0;
#100
t_a=1'b1;
t_b=1'b1;
end
endmodule
