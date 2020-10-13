
students={}
for i in range(3):
    bprint={'name':0,'class':0,'subjects':0}
    bprint['name']=raw_input("Enter name of student"+str(i)+":")
    bprint['class']=raw_input("Enter class of student {0}:".format(i))
    print("Enter subjects:")
    bprint['subjects']=list(map(str,raw_input().split()))
    students['s1']=bprint
print(students)
    
