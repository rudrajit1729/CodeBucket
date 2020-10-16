module FullAdd_tb;
reg t_a,t_b,t_c;
wire t_sum,t_carry;
FullAdd my_gate(.a(t_a),.b(t_b),.c(t_c),.sum(t_sum),.carry(t_carry));
initial
begin
$monitor(t_a,t_b,t_c,t_sum,t_carry);
t_a=1'b0;
t_b=1'b0;
t_c=1'b0;
#100
t_a=1'b0;
t_b=1'b0;
t_c=1'b1;
#100
t_a=1'b0;
t_b=1'b1;
t_c=1'b0;
#100
t_a=1'b0;
t_b=1'b1;
t_c=1'b1;
#100
t_a=1'b1;
t_b=1'b0;
t_c=1'b0;
#100
t_a=1'b1;
t_b=1'b0;
t_c=1'b1;
#100
t_a=1'b1;
t_b=1'b1;
t_c=1'b0;
#100
t_a=1'b1;
t_b=1'b1;
t_c=1'b1;
end
endmodule

