import math

def get_digits(n):
    digits = []
    
    while n >= 1:
        digits.append(n % 10)
        n = int(n / 10)

    return digits

n = 3
total = 0
while True:
    sum_factorial = sum(math.factorial(a) for a in get_digits(n))
    if sum_factorial == n:
        total += n
        print (n)

    print ("difference: %d" % (sum_factorial - n))

    n += 1
