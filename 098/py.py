#!/usr/bin/python

import sys

text = sys.stdin.read()
words = text.split(",")
print(max([len(str) for str in words]))
