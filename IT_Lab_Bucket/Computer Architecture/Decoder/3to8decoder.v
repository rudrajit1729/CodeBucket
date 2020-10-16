module decode3to8(CNT,I,Z);
input CNT;
input [2:0]I;
output [7:0]Z;
nand4gate n1(~I[0],~I[1],~I[2],CNT,Z[0]),
	n2(I[0],~I[1],~I[2],CNT,Z[1]),
	n3(~I[0],I[1],~I[2],CNT,Z[2]),
	n4(I[0],I[1],~I[2],CNT,Z[3]),
	n5(~I[0],~I[1],I[2],CNT,Z[4]),
	n6(I[0],~I[1],I[2],CNT,Z[5]),
	n7(~I[0],I[1],I[2],CNT,Z[6]),
	n8(I[0],I[1],I[2],CNT,Z[7]);
endmodule
