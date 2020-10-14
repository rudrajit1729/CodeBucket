# author - Souvik Dutta

import turtle
import math
import random

win = turtle.Screen()
win.bgcolor("black")

colors = ["white", "yellow", "blue", "orange", "pink"]
decrement = [4, 10, 5, 19, 20]

def drawCircles(t, size, ind):
	dec = decrement[ind]
	L = 4
	if ind == 0:
		L = 10
	for i in range(L):
		t.circle(size)
		size -= dec

def drawSpecial(t, size, repeat, ind):
	for i in range(repeat):
		drawCircles(t, size, ind)
		t.right(360/repeat)

for i in range(len(colors)):
	col = colors[i]
	obj = turtle.Turtle()
	obj.speed(0)
	obj.color(col)
	drawSpecial(obj, 100, 10, i)



