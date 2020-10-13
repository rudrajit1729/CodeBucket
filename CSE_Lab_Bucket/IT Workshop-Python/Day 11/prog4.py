import matplotlib.pyplot as plt
labels=["Python","C++","Ruby","Java"]
sizes=[123,133,18,132]
colors=["red","green","yellow","orange"]
explode(0,1,0,0)
plt.pie(sizes,explode=explode,labels=labels,colors=colors,
        autopct="%1.1f%%",shadow=True,startangle=140)
plt.axis("equal")
plt.show()
