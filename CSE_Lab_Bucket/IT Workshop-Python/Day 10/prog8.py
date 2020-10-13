import datetime
print("enter date DD/MM/YYYY")
day=list(map(int,raw_input().split("/")))
print(datetime.datetime(day[2],day[1],day[0]))
