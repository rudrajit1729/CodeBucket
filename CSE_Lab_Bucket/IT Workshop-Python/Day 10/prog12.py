import datetime
import calendar
print("enter date DD/MM/YYYY")
day=list(map(int,raw_input().split("/")))
m=calendar.month_name[day[1]]
print("Month name:{0}".format(m))
y=day[2]
for i in range(1,13):
    j=calendar.monthcalendar(y,i)
    if j[0][0]!=0:
        break
m=calendar.month_name[i]
print("Month name:{0}".format(m))
