def is_pentagonal(n):
    # See proof for this function in 45.py
    return (1 + (1 + 24 * n)**0.5) / 6 % 1 == 0

pentagonal_numbers = []
n = 1
while True:
    p = n * (3 * n - 1) / 2

    for p2 in pentagonal_numbers:
        if is_pentagonal(p + p2) and is_pentagonal(p - p2):
            print ("D = %d - %d = %d" % (p, p2, p - p2))
            exit()

    pentagonal_numbers.append(p)
    n += 1
