d={}
for i in range(int(raw_input("enter no.of keys"))):
    k=raw_input("Key=")
    if (int(raw_input("enter no.of values"))>1):
        print("Enter values:")
        v=list(map(int,raw_input().split()))
    else:
        v=raw_input("enter value")
    d[k]=v
if (raw_input("Enter") in d):
    print("Present")
else:
    print("Not present")
    
'''
enter no.of keys5
Key=1
enter no.of values3
Enter values:
3 2 1
Key=2
enter no.of values1
enter value4
Key=3
enter no.of values1
enter value5
Key=4
enter no.of values1
enter value3
Key=6
enter no.of values2
Enter values:
7 8
Enter4
Present'''
