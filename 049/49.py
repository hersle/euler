def get_digits(n):
    digits = []
    while n >= 1:
        digit = n % 10
        digits.append(digit)
        n = int(n / 10)
    digits.reverse()
    return digits

def are_permutations(n1, n2, n3):
    l1, l2, l3 = get_digits(n1), get_digits(n2), get_digits(n3)
    if len(l1) != len(l2) != len(l3):
        return False
    for element in l1:
        if not element in l2 or not element in l3:
            return False
        l2.remove(element)
        l3.remove(element)
    return True

def is_prime(n):
    if n < 2:
        return False
    if n % 2 == 0:
        return n == 2
    for d in range(3, int(n**0.5 + 1), 2):
        if n % d == 0:
            return False
    return True

for n in range(1001, 10000, 2):  # odd numbers only
    if is_prime(n):
        n2 = n + 3330
        n3 = n + 6660
        if is_prime(n2) and is_prime(n3) and are_permutations(n, n2, n3):
            print ("%d %d %d" % (n, n2, n3))
