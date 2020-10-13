import datetime
y=str(datetime.date.today().strftime("%Y"))
d=str(datetime.date.today().strftime("%d"))
dt=str(datetime.datetime.now())
t=dt[12:20]
m=dt[5:7]
print("year:{0}\nmonth:{1}\nday:{2}\ntime:{3}\ndate and time:{4}/{5}/{6},{7}\n".format(y,m,d,t,m,d,y,t))

