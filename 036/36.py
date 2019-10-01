"""
Works as well:
--------------

max = 1000000
p = []
for l in range(0, int(max**0.5)):
    s = str(l) if l != 0 else ""
    if s != "":
        p.append(s + s[::-1])

    if l < int(max**0.5 / 10):
        for m in range(0, 10):
            p.append(s + str(m) + s[::-1])

sum = 0
for n in p:
    b = str(bin(int(n)))[2:]
    if b == b[::-1]:
        sum += int(n)
print (sum)
"""

sum = 0
for n in range(1, 1000000):
    d = str(n)
    b = str(bin(n))[2:]
    if d == d[::-1] and b == b[::-1]:
        sum += n
print (sum)
