n = int(input())
heights = [int(x) for x in input().split()]
stack = [-1]
res = 0
heights.append(-1)

for idx, val in enumerate(heights):
    while val < heights[stack[-1]]:  #如果小于栈顶元素则谈栈
        h = heights[stack.pop()]
        res = max(res, h * (idx - stack[-1] - 1))   #每次弹栈后，都计算面积
    stack.append(idx)
print(res)