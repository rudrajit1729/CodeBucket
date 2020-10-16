module mux4x1(I,S,O);
input [3:0] I;
input [1:0]S;
output O;
wire [1:0] r;
mux2x1 M1(I[1:0],S[0],r[0]);
mux2x1 M2(I[3:2],S[0],r[1]);
mux2x1 M3(r[1:0],S[1],O);
endmodule
