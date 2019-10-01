def is_prime(n):
    if n < 2:
        return False
    if n % 2 == 0:
        return n == 2
    for d in range(3, int(n**0.5) + 1, 2):
        if n % d == 0:
            return False
    return True

n = 9  # first odd composite number
while True:
    if not is_prime(n):
        # Search for a number a, so that the number can be written as 
        # n = x + 2a², where x, the difference between n and 2a², should 
        # be a prime number.
        for a in range(1, int(n**0.5) + 1):
            if is_prime(n - 2 * a**2):
                print ("%d = %d + %d * %d²" % (n, n - 2 * a**2, 2, a))
                break
        if a == int(n**0.5):
            print (n)
            break
    n += 2
