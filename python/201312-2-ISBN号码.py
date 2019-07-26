isbn = input()
ch = isbn[-1]
ss = ''.join(isbn.split('-')[:3])
sum = 0
cnt = 1
for c in ss:
    sum += int(c) * cnt
    cnt += 1

mod = sum % 11

if ch == str(mod) or ch == 'X' and mod == 10:
    print("Right")
else:
    if mod == 10:
        print(isbn[:-1] + 'X')
    else:
        print(isbn[:-1] + str(mod))
