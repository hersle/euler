def is_prime(n):
    if n < 2:
        return False
    if n % 2 == 0:
        return n == 2
    for d in range(3, int(n**0.5) + 1):
        if n % d == 0:
            return False
    return True

# Find all primes that add up to a sum smaller than 1 000 000
primes = []
s = 0
n = 0
while s < 10**6 and s + n < 10**6:
    if is_prime(n):
        primes.append(n)
        s += n
    n += 1

# Find the longest chain of primes whose sum is less than 1 000 000
longest_chain_length = 0
longest_chain_sum = 0
for start in range(0, len(primes)):  # index to start counting from
    for finish in range(len(primes), start, -1):  # index to finish counting at
        chain = primes[start:finish]
        chain_sum = sum(chain)
        chain_length = len(chain)
        if chain_length > longest_chain_length and is_prime(chain_sum):
            longest_chain_length = chain_length
            longest_chain_sum = chain_sum

print (longest_chain_sum)
