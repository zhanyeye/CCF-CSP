#!/usr/bin/env python3
# coding=utf-8

isbn = input()
ch = isbn[-1]
ss = ''.join(isbn.split('-')[:3])
sum = 0
cnt = 1
for c in ss:
    sum += int(c) * cnt
    cnt += 1

mod = sum % 11

print(mod)

if mod < 10 and mod == int(ch) or mod == 10 and ch == 'X':
    print("Right")
else:
    print(isbn[:-1] + str(mod) if mod < 10 else 'X')
