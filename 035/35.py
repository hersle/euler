import math

# Move last digit to front
def rotate_number(n):
    last_digit = n % 10
    n_digits = int(math.log10(n))
    n = int(n / 10)
    return last_digit * 10**n_digits + n

def is_prime(n):
    if n < 2:
        return False
    if n % 2 == 0:
        return n == 2
    for a in range(3, int(n**0.5) + 1, 2):
        if n % a == 0:
            return False
    return True

n_circular_primes = 0
for n in range(1, 10**6):
    n_rotations = int(math.log10(n) + 1)

    is_circular_prime = True
    for i in range(0, n_rotations):
        if not is_prime(n):
            is_circular_prime = False
            break
        n = rotate_number(n)

    if is_circular_prime:
        n_circular_primes += 1
        print (n)

print (n_circular_primes)
