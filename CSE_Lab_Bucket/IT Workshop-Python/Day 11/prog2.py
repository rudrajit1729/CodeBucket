import matplotlib.pyplot as plt
x=[1,2,3]
y=[2,4,1]
plt.plot(x,y,label="line1")
plt.xlabel("Time")
plt.ylabel("Population")
plt.title("Census")
plt.plot(x,y,'-x',xolor='grey',markersize=15,linewidth=4,markerfacecolor='white'
         ,markeregdecolor='grey',markeregdewidth=2)
plt.xlim(0,5)
plt.ylim(0,5)
plt.show()
