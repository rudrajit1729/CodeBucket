import turtle, random
def setup():
    global length, height, scale, strange, solve
    strange="false"
    solve="false"
    f = open("Config.txt", "r")
    for lines in f:
        lines=lines.strip('\n')
        items = lines.split("= ")
        if(items[0]=="length"):
            length=int(items[1])
        elif(items[0]=="height"):
            height=int(items[1])
        elif(items[0]=="scale"):
            scale=int(items[1])
        elif(items[0]=="strange? (y/n)" and items[1]=="y"):
            strange="true"
        elif(items[0]=="solve (y/n)" and items[1]=="y"):
            solve="true"
def grid():
    global grid,visit,visited,heights,rows,total,height
    grid=[]
    visit=[]
    visited=[]
    heights=height//scale
    rows=length//scale
    total=rows*heights
    counter=0
    while(total!=counter):
        grid.append(counter)
        visit.append(0)
        visited.append(counter)
        visited.append(0)
        counter+=1
def NESW(current):
    cords=[current+rows,current+1,current-rows,current-1]
    stats=[]
    for i in cords:
        if(i>total-1 or i<0 or (i//rows!=current//rows and i%rows!=current%rows)):
            stats.append(3)
        else:
            stats.append(visit[i])
    if(visit[current]<=min(stats)):
        return visited[(current*2)+1]
    counter=0
    for i in stats:
        if(i==min(stats)):
            counter+=1
    options=[1,3]
    choice=options[random.randint(0,1)]
    if(strange=="true" and counter==choice):
        return visited[(current*2)+1]
    NESW=random.randint(0, counter-1)
    counter=0
    count=0
    for i in stats:
        if(i==min(stats)):
            if(counter==NESW):
                visit[cords[count]]+=1
                visited[(grid[cords[count]]*2)+1]=current
                return grid[cords[count]]
            counter+=1
        count+=1
def tset():
    global t,wn
    wn=turtle.Screen()
    wn.bgcolor("grey")
    t=turtle.Turtle()
    t.ht()
    t.speed(0)
    t.pensize(scale-(scale*.2))
    t.color("white")
    t.up()
    t.goto((-.5*rows)*scale,(-.5*heights)*scale)
    t.pendown()
def generate():
    visit[0]=1
    previous=0
    while(min(visit)!=1):
        previous=NESW(previous)
        t.goto(((previous % rows)-.5*rows)*scale,((previous // rows)-.5*heights) * scale)
def solver():
    path=grid[total-1]
    t.down()
    t.color("purple")
    while(path!=0):
        path=visited[(path*2)+1]
        t.goto(((path % rows)-.5*rows)*scale,((path // rows)-.5*heights) * scale)
def StartStop():
    global path
    t.pensize(scale*.6)
    t.up()
    t.goto((-.5*rows)*scale,(-.5*heights)*scale)
    t.down()
    t.seth(180)
    t.color("green")
    t.forward(scale)
    t.up()
    path=grid[total-1]
    t.goto(((path % rows)-.5*rows)*scale,((path // rows)-.5*heights) * scale)
    t.down()
    t.color("red")
    t.seth(0)
    t.forward(scale)
    t.up()
    t.backward(scale)
def main():
    setup()
    grid()
    tset()
    generate()
    StartStop()
    if(solve=="true"):
        solver()
    wn.exitonclick()
main()
