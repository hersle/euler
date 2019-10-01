s = 0
for n in range(3, 1000, 3):
    s += n
for n in range(5, 1000, 5):
    s += n
for n in range(3 * 5, 1000, 3 * 5):
    s -= n
print (s)
