#!/usr/bin/env python3
# coding=utf-8
n = int(input())
# a = [int(x) for x in input().split()]
a = list(map(int, input().split()))
b = list(set(a))   # 化为集合，去掉相同的数
b.sort()           # 排序
d = dict(zip(b, map(a.count, b)))   #将数与它的出现次数组合再转化为字典
print(max(d, key = d.get))   # 从字典中选出最大的数
