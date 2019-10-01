def get_permutations(elements):
    if len(elements) == 1:
        return [elements]
    permutations = []
    pivot = elements[0]
    for permutation in get_permutations(elements[1:]):
        for i in range(0, len(permutation) + 1):
            permutations.append(permutation[:i] + [pivot] + permutation[i:])
    return permutations

def get_number(digits):
    n = 0
    for power, digit in enumerate(reversed(digits)):
        n += digit * 10**power
    return n

pandigital_sum = 0
primes = [2,3,5,7,11,13,17]
for digits in get_permutations([0,1,2,3,4,5,6,7,8,9]):
    if digits[0] != 0:
        n = get_number(digits)
        is_divisible = True
        for i, prime in enumerate(primes, start=1):
            sub_n = get_number(digits[i:i+3])
            if sub_n % prime != 0:
                is_divisible = False
                break
        if is_divisible:
            pandigital_sum += n
            print (n)

print ("sum = %d" % pandigital_sum)
