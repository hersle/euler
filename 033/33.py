nominator = 1
denominator = 1

for a in range(10, 100):
    for b in range(a + 1, 100):

        for n in str(a):
            if n != '0' and n in str(b):
                new_a = int(str(a).replace(n, "", 1))
                new_b = int(str(b).replace(n, "", 1))

                if new_b != 0 and new_a / new_b == a / b:
                    nominator *= a
                    denominator *= b

                break

print ("%d / %d" % (nominator, denominator))
