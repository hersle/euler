#!/usr/bin/python

import math

n = 3
d = 2
count = 0
for i in range(1, 1001):
    n, d = 2 * d + n, d + n
    if int(math.log10(n)) > int(math.log10(d)):
        count += 1
print (count)
