sum = 0
i = 2
while True:
    digit_pow_sum = 0
    for digit in str(i):
        digit_pow_sum += int(digit)**5
    if digit_pow_sum == i:
        sum += digit_pow_sum
        print ("%s, current sum = %s" % (digit_pow_sum, sum))
    i += 1
