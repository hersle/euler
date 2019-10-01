#!/usr/bin/python

def is_lychrel(n):
    for i in range(50):
        n += int(str(n)[::-1])
        if str(n) == str(n)[::-1]:
            return False
    return True

print (sum(1 for n in range(1, 10001) if is_lychrel(n)))
