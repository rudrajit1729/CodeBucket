//Generation of Moore FSM to detect a binary seq from a digital input

`timescale 1ns / 1ps

module Moore(input a, clk, rst, output reg q, output [3:0] current);
reg [3:0]c,n;
parameter zero=4'b0000, one=4'b0001, onezero=4'b0010, ozo=4'b0101, ozoo=4'b1011;
always @(posedge clk, posedge rst) begin
	if(rst==1) c<=zero;
	else c<=n;
end

always @(c,a)
begin
 case(c) 
 zero:begin
  if(a==1) n <= one;
  else n <= zero;
 end
 
 one:begin
  if(a==0) n <= onezero;
  else n <= one;
 end
 
 onezero:begin
  if(a==0) n <= zero;
  else n <= ozo;
 end 
 
 ozo:begin
  if(a==0) n <= onezero;
  else n <= ozoo;
 end
 
 ozoo:begin
  if(a==0) n <= onezero;
  else n <= one;
 end	
 
 default:n <= zero;
 endcase
end		

always @(c)
begin 
 case(c) 
 zero:   q <= 0;
 one:   q <= 0;
 onezero:  q <= 0;
 ozo:  q <= 0;
 ozoo:  q <= 1;
 default:  q <= 0;
 endcase
end 
assign current=c;
endmodule

