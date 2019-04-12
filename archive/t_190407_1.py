"""
题目描述
小Q在进行一个对数字进行拆分的游戏，游戏规则如下:
小Q最初只有一个整数N，接下来每一轮中，小Q被允许对现有的每个数进行下面两
个操作之一-:
1、对当前小Q手里的所有数减1
2、把所有数都拆分为更小的两个数之和
但是拆分操作只允许使用至多k次，现在小Q想知道把N完全消去需要多少轮操作。

输入描述:
输入一行包含两个整数N,K (1 ≤ N <=100, 0 <= K <= 100)
输出描述:
输出一个整数，表示至少需要的轮数。

5 2
4

15 4
5
"""

import math

n, k = map(int, input().split())
res = 0
while (n > 1 and k):
    k -= 1
    n = n // 2 + n % 2
    res += 1
res += n
print(res)
