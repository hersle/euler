def get_digits(n):
    digits = []
    while n >= 1:
        digits.append(n % 10)
        n = int(n / 10)
    return digits

products = []
for a in range(1, int(9876**0.5) + 1):
    for b in range(int(9876**0.5), 9876 + 1):
        product = a * b
        digits = get_digits(a) + get_digits(b) + get_digits(product)

        if len(digits) == 9:
            is_pandigital = True
            for digit in range(1, 10):
                if digits.count(digit) != 1:
                    is_pandigital = False
                    break

            if is_pandigital and product not in products:
                products.append(product)
                print ("%d * %d = %d" % (a, b, product))

print ("sum = %d" % sum(products))
