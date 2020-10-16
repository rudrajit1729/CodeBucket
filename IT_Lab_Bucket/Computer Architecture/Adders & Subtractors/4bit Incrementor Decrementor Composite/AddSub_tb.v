module AddSub4Bit_tb;
reg [3:0]t_a,t_b;
reg t_c;
wire [3:0]t_result;
wire t_cout;
AddSub4Bit my_gate(.a(t_a),.b(t_b),.c(t_c),.result(t_result),.cout(t_cout));
initial
begin
$monitor(t_a,t_b,t_c,t_result,t_cout);
t_a=4'h5;
t_b=4'h6;
t_c=1'b0;
#100
t_a=4'h9;
t_b=4'h6;
t_c=1'b1;
#100
t_a=4'h9;
t_b=4'h6;
t_c=1'b0;
#100
t_a=4'h5;
t_b=4'h6;
t_c=1'b1;
end
endmodule

