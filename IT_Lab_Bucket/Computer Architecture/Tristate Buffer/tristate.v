module tristate(CNT,I,Z);
input CNT,I;
output Z;
assign Z=(CNT==1)?1'bz:I;
endmodule