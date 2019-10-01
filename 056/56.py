#!/usr/bin/python

digit_sum_max = 0
for a in range(1, 101):
    for b in range(1, 101):
        n = a**b
        digit_sum = sum(int(digit) for digit in str(n))
        if digit_sum > digit_sum_max:
            digit_sum_max = digit_sum

print (digit_sum_max)
