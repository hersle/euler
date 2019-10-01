#!/usr/bin/python

import math

def ncr(n, r):
    return math.factorial(n) / math.factorial(n - r) / math.factorial(r)

count = 0

for n in range(1, 101):
    for r in range(0, n + 1):
        if ncr(n, r) > 1000000:
            count += 1
        print ("n = %d, r = %d, ncr = %d" % (n, r, ncr(n, r)))
    print ()

print ("count = %d" % count)
