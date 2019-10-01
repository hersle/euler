#!/usr/bin/python

def f(n):
    return n**2 if n < 10 else (n % 10)**2 + f(int(n / 10))

count = 0
for n in range(1, 10000000):
    print (n)
    a = n
    while a != 1 and a != 89:
        a = f(a)
    if a == 89:
        count += 1

print (count)
