'''
题目描述:
随着新能源车的普及，网易越来越多的同事开电动车上下班通勒。网易大厦停车场里可以提供使
用的电桩数量是S, 1 <= S <= 100, 现在有N台电动车等待充电，1 <= N <= 999，第i台电动车所需
要的充电时间为t, 1 <= i <= N, S、N、t均为正整数。

输入为2行，第-行N s,分别为N台电动车和S个电桩，以空格分隔，第二行为每台电动牛允电
所需的时长ti，以空格分隔，如:

Input:
3 2
2 1 3
Output:
3
'''
from bisect import bisect_left

n, s = map(int, input().split())
times = map(int, input().split())
times = sorted(times)[::-1]
values = [0] * s

for t in times:
    tmp = values[0] + t
    ind = bisect_left(values, tmp)
    values.insert(ind, tmp)
    values = values[1:]

print(values[-1])
