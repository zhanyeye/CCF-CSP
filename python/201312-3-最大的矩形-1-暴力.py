n = int(input())
height = [int(x) for x in input().split()]
ans = 0
for i in range(n):
    h = height[i]
    for j in range(i, n):
        h = min(h, height[j])
        ans = max(ans, h * (j - i + 1))
print(ans)