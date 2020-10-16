module xor2gate_tb;
reg a,b;
wire y;
xor2gate my_gate(.a(a),.b(b),.y(y));
initial
begin
a=1'h0;
b=1'h0;
#100
a=1'h0;
b=1'h1;
#100
a=1'h1;
b=1'h0;
#100
a=1'h1;
b=1'h1;
end
endmodule
