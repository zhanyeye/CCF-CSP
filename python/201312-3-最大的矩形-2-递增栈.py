n = int(input())
height = [int(x) for x in input().split()]
res, i = 0, 0
stack = []
while i < n:
    if not stack or height[i] >= height[stack[-1]]:   # 注意是大于等于
        stack.append(i)
        i += 1
    else:
       tmp = stack.pop()
       res = max(res, height[tmp] * ((i - stack[-1] - 1) if stack else i))
while stack:
    tmp = stack.pop()
    res = max(res, height[tmp] * ((i - stack[-1] - 1) if stack else i))
print(res)
