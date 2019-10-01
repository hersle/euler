def factorize(n):
    for d in range(2, int(n**0.5) + 1):
        if n % d == 0:
            return [d] + factorize(n / d)
    return [int(n)]

n = 1
consecutive = 0
while True:
    factors_distinct = set(factorize(n))
    if len(factors_distinct) == 4:
        print ("%d -> %s" % (n, str(factors_distinct)))
        consecutive += 1
        if consecutive == 4:
            print (n - 4 + 1)
            break
    else:
        consecutive = 0

    n += 1
