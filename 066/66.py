#!/usr/bin/python

def is_square(n):
    rt = int(n**0.5)
    return rt * rt == n

for d in range(2, 100):
    if is_square(d):
        continue

    k = 1
    while True:
        y_sq = 2 * k + k * k * d
        if is_square(y_sq):
            x = 1 + k * d
            break
        y_sq = -2 * k + k * k * d
        if is_square(y_sq):
            x = -1 + k * d
            break
        k += 1
    print ("d = %04d: %d^2 - %d * %d = %d" % (d, x, d, y_sq, 1))
