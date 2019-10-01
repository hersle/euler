def factorize(n):
    for d in range(2, int(n**0.5) + 1):
        if n % d == 0:
            return [d] + factorize(n / d)
    return [n]

print (max(factorize(600851475143)))
