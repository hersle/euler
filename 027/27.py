# n^2 + an + b
# n >= 0
# |a| < 1000
# |b| < 1000
# find product of coefficents a and b for the quadratic expression that 
# produces the highest number of primes for consecutive values of n

def is_prime(numerator):
    if numerator < 2:
        return False
    for denominator in range(2, int(numerator**0.5) + 1):
        if numerator % denominator == 0:
            return False
    return True

max_primes = 0
max_a = 0
max_b = 0
for a in range(-999, 1000):
    for b in range(-999, 1000):
        formula = "n^2 + %sn + %s" % (a, b)
        n = 0
        while is_prime(abs(n*n + a*n + b)):
            n += 1
        if n > max_primes:
            print (formula + " produced %s primes" % n)
            max_primes = n
            max_a = a
            max_b = b
print ("n^2 + an + b produced %s primes when a * b = %s * %s = %s" %
        (max_primes, max_a, max_b, max_a * max_b))
