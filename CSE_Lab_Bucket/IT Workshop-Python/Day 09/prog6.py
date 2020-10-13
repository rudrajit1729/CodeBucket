with open("myfile2.txt",'w') as f :
          f.write("Hi!!!How are you doing!!!")
          #print(f.read())
          f.close()

with open("myfile2.txt",'r') as f :
        print(f.read())
        f.close()
