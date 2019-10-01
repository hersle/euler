s = 0
a, b = 1, 2
while b < 4 * 10**6:
    if b % 2 == 0:
        s += b
    a, b = b, a + b
print (s)
