#!/usr/bin/python

from math import floor, sqrt

def func(n, a, b, c, N):
	i = (a + floor(sqrt(b))) // c
	if n == N:
		return (i, 1)
	else:
		a = i * c - a
		c = (b - a * a) // c
		(xx, yy) = func(n + 1, a, b, c, N)
		return (yy + xx * i, xx)

for D in range(1, 10000):
	if floor(sqrt(D)) * floor(sqrt(D)) != D:
		N = 1
		while True:
			(x, y) = func(0, 0, D, 1, N)
			if x * x - D * y * y == 1:
				break
			N += 1
		print("%d^2 - %d * %d^2 = %d" % (x, D, y, x * x - D * y * y))

