import math

palindrome_largest = 0

for a in range(1000, 100, -1):
    # Break if it is impossible to generate a higher palindrome
    if a * 1000 < palindrome_largest:
        break

    for b in range(1000, 100, -1):
        p = a * b
        digits = int(math.log10(p)) + 1

        # Last half of number from right to left
        last = 0
        for i in range(0, int(digits / 2)):
            last += (p % 10) * 10**(int(digits / 2) - 1 - i)
            p = int(p / 10)

        # First half of number from left to right
        # Excludes the middle digit if the number has an odd number of digits
        first = int(p / 10**(digits % 2))

        if first == last and a * b > palindrome_largest:
            palindrome_largest = a * b

print (palindrome_largest)
