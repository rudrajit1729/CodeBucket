

import matplotlib.pyplot as plt
x=[1,2,3,5,7,3,9,6,8,3,8,4]
y=[2,4,1,2,3,7,4,9,6,9,2,1]
plt.scatter(x,y,label="line`1",marker="*")
plt.xlabel("Time")
plt.ylabel("Population")
plt.title("Census")
plt.legend()
plt.show()
