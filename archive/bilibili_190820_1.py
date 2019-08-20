"""
1-A, 2-B, ..., 26-Z
输入数字 N，共有多少种可能的结果


111

3
说明： AAA AK KA 三种

10
1
"""


def main():
    s = '0' + input()
    length = len(s)
    dp = [0] * length
    dp[0] = dp[1] = 1
    for i in range(2, length):
        if s[i] != '0':
            dp[i] += dp[i-1]
        if 9 < int(s[i-1:i+1]) < 26:
            dp[i] += dp[i-2]
    print(dp[length-1])


if __name__ == "__main__":
    main()
