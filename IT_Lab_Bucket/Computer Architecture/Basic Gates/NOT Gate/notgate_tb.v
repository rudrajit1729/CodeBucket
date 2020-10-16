module notgate_tb;
reg a;
wire y;
notgate my_gate(.a(a),.y(y));
initial
begin
a=1'h0;
#100
a=1'h1;
end
endmodule
