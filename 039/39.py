solutions_max = 0
p_max = 0

for p in range(1, 1000 + 1):
    solutions = 0

    for c in range(1, p):
        # Pythagorean equation:
        # a² + b² = c²
        # Perimeter sum of the triangle: 
        # p = a + b + c
        # a = p - b - c
        # Inserting a into the pythagorean equation:
        # (p - b - c)² + b² = c²
        # p² - pb - pc - pb + b² + bc - pc + bc + c² + b² = c²
        # p² + b² + b² + c² - c² - pb - pb - pc - pc + bc + bc = 0
        # p² + 2b² - 2pb - 2pc + 2bc = 0
        # 2b² - 2pb + 2bc + p² - 2pc = 0
        # 2b² - 2(p - c)b + p² - 2pc = 0
        # This forms a quadratic equation in which, since p and c are known, 
        # ... the coefficient in the second-degree term is 2
        # ... the coefficient in the first-grade term is -2(p - c)
        # ... the constant term is p² - 2pc

        a = 2
        b = -2 * (p - c)
        c = p**2 - 2 * p * c

        if b**2 - 4 * a * c >= 0:
            #               ________
            #        -b ± \/b² - 4ac|
            # Side = ----------------, b² - 4ac >= 0
            #               2a

            s1 = (-b + (b**2 - 4 * a * c)**0.5) / (2 * a)
            s2 = (-b - (b**2 - 4 * a * c)**0.5) / (2 * a)
            # Sides are valid if their lengths are integral and > 0
            if s1 > 0 and s2 > 0 and s1 % 1 == 0 and s2 % 1 == 0:
                print ("sides %d and %d" % (s1, s2))
                solutions += 1

    if solutions > solutions_max:
        solutions_max = solutions
        p_max = p

print ("p = %d has the most solutions with %d solutions" % (p_max, solutions_max))
