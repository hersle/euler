#!/usr/bin/python

w_max = int(-1/2 + 4000000**0.5)
diff_best = 2000000
for w in range(1, w_max + 1):
    for d in range(0, 2):
        h = int(-1/2 + (8000000 / w / (w+1) + 1/4)**0.5) + d
        n = w*(w+1)*h*(h+1)/4
        diff = abs(n - 2000000)
        if diff < diff_best:
            diff_best = diff
            print ("%r * %r = %r: %r" % (w, h, w * h, n))
