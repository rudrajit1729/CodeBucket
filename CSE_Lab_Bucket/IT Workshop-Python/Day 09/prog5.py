import os
f=open("file3.txt","w")
f.write("abcdefghijklmnop")
f.close()
try:

        os.remove("file3.txt")
        print("File deleted")
    
except Exception as e:
    print("File not found")
    print(e)
    
