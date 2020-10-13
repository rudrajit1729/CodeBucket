from random import randint as r
import matplotlib.pyplot as plt
ages=[r(2,50) for x in range(50)]
range=(0,100)
bins=10
plt.plot(ages,bins,range,color="green",histtype='bar',rwidth=0.8)
