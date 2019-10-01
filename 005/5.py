# Find lcm of 1, 2, 3, ..., 20

def factorize(n):
    for d in range(2, int(n**0.5) + 1):
        if n % d == 0:
            return [d] + factorize(n / d)
    return [n]

factors = []
for n in range(1, 20 + 1):
    factors.append(factorize(n))
print (factors)
