module incre4bit_tb;
reg [3:0]t_a;
wire [3:0]t_b;
wire t_cout;
incre4bit my_gate(.a(t_a),.b(t_b),.cout(t_cout));
initial
begin
$monitor(t_a,t_b,t_cout);
t_a=4'h5;
#10
t_a=4'h9;
#10
t_a=4'ha;
#10
t_a=4'hf;
end
endmodule
