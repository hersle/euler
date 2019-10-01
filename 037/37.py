import math

def is_prime(n):
    if n < 2:
        return False
    if n % 2 == 0:
        return n == 2
    for d in range(3, int(n**0.5) + 1):
        if n % d == 0:
            return False
    return True

def is_truncatable_prime(n):
    n2 = n
    while n >= 1:  # remove digits from left
        if not is_prime(n):
            return False
        n = n % 10**int(math.log10(n))
    while n2 >= 1:  # remove digits from right
        if not is_prime(n2):
            return False
        n2 = int(n2 / 10)
    return True

# TODO: cannot contain 4, 6 or 8 (can start with 2)
n = 11  # 2, 3, 5, 7 not considered truncatable primes
s = 0
c = 0
while c < 11:
    if is_truncatable_prime(n):
        print (n)
        s += n
        c += 1
    n += 2

print ("sum = %d" % s)
