"""
题目描述
一天，小Q得到了一个包含n个数字的数组，他想对这个数组进行k次如下的操作:
首先找出数组中最小的非0数字x，输出它，然后把数组中的所有非零数字都减去x;
如果数组中的数字都是0，那么直接输出0。

输入描述:
第一行两个数字n和k，用一个空格分隔;
第二行n个数字，每两个数字之间用一个空格分隔。
满足1 <= n,k<= 10，数组中的所有数字 ai 满足1 <= ai<= 10
输出描述:
k行，每行一一个整数。

4 1
5 5 7 2

2


2 2
4 6

4
2
"""

import math

n, k = map(int, input().split())
arr = map(int, input().split())
arr = sorted(arr)
for i in range(n-1, 0, -1):
    arr[i] -= arr[i-1]

ind = 0
for i in range(k):
    while ind < n and arr[ind] == 0:
        ind += 1
    if ind >= n:
        print(0)
    else:
        print(arr[ind])
        ind += 1
