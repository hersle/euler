import math

# Returns the number a concatenated with number b
def concat(a, b):
    b_digits = int(math.log10(b) + 1)
    return a * 10**b_digits + b

# Returns a list of all the digits in the number
def get_digits(n):
    digits = []
    while n >= 1:
        digits.append(n % 10)
        n = int(n / 10)
    return digits

# Returns true if the number is pandigital from 1 through 9, otherwise False
def is_pandigital(n):
    n = get_digits(n)
    for a in range(1, 9 + 1):
        if n.count(a) != 1:
            return False
    return n.count(0) == 0

# Any number above 10000 cannot form a concatenated product with at least two 
# integers 1, 2, ..., n. 10000 concatenated with 10000 * 2 = 1000020000 is 10 
# digits long, and hence cannot form a pandigital number <= 987654321
n_biggest = 0
for a in range(1, 10000):
    b = 1
    n = a
    while int(math.log10(n) + 1) < 9:
        b += 1
        n = concat(n, a * b)
    if is_pandigital(n):
        if n > n_biggest: n_biggest = n
        print ("%d * (%d to %d) -> %d" % (a, 1, b, n))
print ("biggest: %d" % n_biggest)
