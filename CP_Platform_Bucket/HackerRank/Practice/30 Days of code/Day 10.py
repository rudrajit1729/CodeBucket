n=int(input())
b=bin(n).replace("0b", "")
print (max(map(len, b.split('0')))) 
