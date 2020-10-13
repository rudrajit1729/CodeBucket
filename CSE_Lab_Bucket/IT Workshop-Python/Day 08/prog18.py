student={}
for i in range(3):
    bprint={'name':0,'marks':0}
    bprint['name']=raw_input("Enter name of student {0}:".format(i+1))
    print("enter marks")
    l=list(map(float,raw_input().split()))
    bprint['marks']=l
    total=sum(l)
    student[bprint['name']]=total
    
print(student)
stack=max(zip(student.values(),student.keys()))
print(stack)
