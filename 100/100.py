#!/usr/bin/python

k1 = 1
k2 = 1
while True:
	# print("%d / %d" % (k1, k2))
	if k1 % 2 == 1:
		b = (2 + int((2 * (1 + k1 * k1))**0.5)) / 4
		n = (1 + int((1 + 8 * (b * b - b))**0.5)) / 2
		print("n = %d, b = %d" % (n, b))
		if n > 10**12:
			break
	k1, k2 = k1 + 2 * k2, k1 + k2
