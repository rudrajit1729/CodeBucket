module mux2x1(I,S,O);
input [1:0] I;
input S;
output O;
wire [1:0] r;
assign O=(S==0)?I[0]:I[1];
endmodule
