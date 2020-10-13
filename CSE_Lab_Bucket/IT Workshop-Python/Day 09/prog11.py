x = list(map(int, raw_input('Enter DOB dd/mm/yyyy').split('/')))
print x
dic_leap = {1:31,2:29,3:31,4:30,5:31,6:30,7:31,8:31,9:30,10:31,11:30,12:31}
dic = {1:31,2:28,3:31,4:30,5:31,6:30,7:31,8:31,9:30,10:31,11:30,12:31}
if (x[2] % 100 == 0 and x[2] % 400 == 0) or (x[2] % 4 == 0):
    if dic_leap[x[1]] <= x[0]:
        print('Invalid')
    else:
        print('Valid')
else:
    if dic[x[1]] <= x[0]:
        print('Invalid')
    else:
        print('Valid')
