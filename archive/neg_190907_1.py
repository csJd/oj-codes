"""
题目描述
如果把一个数的各位数字反向排列所得的数和原数样，则称这个数为回文数。给定个十进制的正整
数，判断X在二进制下(去掉前导0)是否是回文数。如11的进制为1011.

输入描述:
输入的第一行是一个正整数T(0 < T <= 100)，表示有 T 组测试数据。对于每一个测试数据包含
一个正整数X (0 < X <= 10000000)。

输出描述:
对于每一组测试样例，如果 x 在二进制下是回文数则输出 YES，否则输出NO。

3
1
4
7

YES
NO
YES
"""

n_cases = int(input())

while n_cases > 0:
    n_cases -= 1
    x = int(input())
    s = f"{x:b}"
    length = len(s)
    for i in range(length//2):
        if s[i] != s[length-1-i]:
            print("NO")
            break
    else:
        print("YES")
