#!/usr/bin/python

from math import floor, sqrt

for D in range(1, 1001):
	isqrt = floor(sqrt(D))
	if isqrt * isqrt != D:
		a, b, c = 0, D, 1
		x2, y2 = 0, 1
		x1, y1 = 1, 0
		while True:
			i = floor((a + isqrt) / c)
			x, y = i * x1 + x2, i * y1 + y2
			print("%d^2 - %d * %d^2 = %d" % (x, D, y, x * x - D * y * y))
			if x * x - D * y * y == 1:
				break
			x1, x2, y1, y2 = x, x1, y, y1
			a = i * c - a
			c = floor((b - a * a) / c)
