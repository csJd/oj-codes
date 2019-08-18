"""
给定一个由 a b c 三种字符组成的字符串，

输入：字符串
输出：子序列 "abc" 的个数

aabbcc
8

abacbc
4

a
0
"""


def main():
    s = input()
    length = len(s)
    dp = [0] * 3
    # dp[i][0] refers to the number of sub-sequence 'a' in s[:i+1]
    # dp[i][1] refers to the number of sub-sequence 'ab' in s[:i+1]
    # dp[i][2] refers to the number of sub-sequence 'abc' in s[:i+1]
    for i, c in enumerate(s):
        if c == 'a':
            dp[0] += 1
        elif c == 'b':
            dp[1] += dp[0]
        elif c == 'c':
            dp[2] += dp[1]
    print(dp[2])


if __name__ == "__main__":
    main()
