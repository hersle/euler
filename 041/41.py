def is_prime(n):
    if n < 2:
        return False
    if n % 2 == 0:
        return n == 2
    for d in range(3, int(n**0.5) + 1, 2):
        if n % d == 0:
            return False
    return True

def get_permutations(elements):
    if len(elements) == 1:
        return [elements]
    pivot = elements[0]
    permutations = []
    for permutation in get_permutations(elements[1:]):
        for i in range(0, len(permutation) + 1):
            permutations.append(permutation[:i] + [pivot] + permutation[i:])
    return permutations

def get_number(digits):
    n = 0
    for power, digit in enumerate(reversed(digits)):
        n += digit * 10**power
    return n

digits = [9,8,7,6,5,4,3,2,1]
while digits:
    max_n = 0
    for n in get_permutations(digits):
        n = get_number(n)
        if is_prime(n) and n > max_n:
            max_n = n
    if max_n:
        print (max_n)
        break
    digits.pop(0)
