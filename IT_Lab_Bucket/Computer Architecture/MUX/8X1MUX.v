module mux8x1(I,S,O);
input [7:0] I;
input [2:0]S;
output O;
wire [1:0] r;
mux4x1 M1(I[3:0],S[1:0],r[0]),
M2(I[7:4],S[1:0],r[1]);

mux2x1 M3(r,S[2],O);

endmodule
