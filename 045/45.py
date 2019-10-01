#Number used by the triangle formula to generate a trinagle number
tn = 285

while True:
    t = tn * (tn + 1) / 2

    # Calculate the number needed by the pentagonal formula for it to 
    # produce the same number.
    # p(n) = n(3n - 1) / 2
    # t = n(3n - 1) / 2
    # 2t = 3n² - n
    # 3n² - n - 2t = 0
    # n = (-(-1) +/- sqrt((-1)² - 4 * 3 * (-2t))) / 2 * 3
    # n = (1 +/- sqrt(1 - 12 * (-2 * t))) / 6
    # n = (1 +/- sqrt(1 + 24 * t)) / 6
    # Prevent negative numbers
    # n = (1 + sqrt(1 + 24 * t)) / 6
    pn = (1 + (1 + 24 * t)**0.5) / 6

    # Calculate the number needed by the hexagonal formula for it to 
    # produce the same number.
    # h(n) = n(2n - 1)
    # t = n(2n - 1)
    # t = 2n² - n
    # 2n² - n - t = 0
    # n = (-(-1) +/- sqrt((-1)² - 4 * 2 * (-t))) / 2 * 2
    # n = (1 +/- sqrt(1 - 8 * (-t))) / 4
    # n = (1 +/- sqrt(1 + 8 * t)) / 4
    # Prevent negative numbers
    # n = (1 + sqrt(1 + 8 * t)) / 4
    hn = (1 + (1 + 8 * t)**0.5) / 4

    # Check if the numbers needed by the pentagonal and hexagonal formula
    # are integers.
    if pn % 1 == 0 and hn % 1 == 0:
        print (t)
        if tn > 285:
            break

    tn += 1
