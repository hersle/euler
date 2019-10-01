#!/usr/bin/python

a = 3
b = 2

for i in range(3, 101):
    m = int(i / 3) * 2 if i % 3 == 0 else 1
    a, b = b + m * a, a
    print ("i = %-3d: %d" % (i, a))

print ("sum: %d" %  sum(int(n) for n in str(a)))
