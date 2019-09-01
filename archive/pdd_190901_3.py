"""
题目描述
扔n个骰子，第i个骰子有可能投掷出X1种等概率的不同的结果，数字从 1 到 xi。
所有骰子的结果的最大值将作为最终结果。求最终结果的期望。

输入描述:
第一行一个整数 n，表示有 n 个骰子。(1<= n <= 50)
第二行n个整数，表示每个骰子的结果数 xi。(2 <= xi <= 50)

输出描述:
输出最终结果的期望，保留两位小数。

2
2 2

1.75
"""


def main():
    n = int(input())
    x = list(map(int, input().split()))
    maxv = max(x)
    exp = 0

    # cnt[i] 记录每个骰子的点数都 <= i 的排列数
    cnt = [1] * (maxv+1)
    cnt[0] = 0
    for i in range(1, maxv+1):
        for xi in x:
            cnt[i] *= min(xi, i)
        # cnt[i] - cnt[i-1] 为最大值为 i 的排列数
        exp += i * (cnt[i] - cnt[i-1])

    # all permutations
    n_pers = 1
    for xi in x:
        n_pers *= xi

    print("%.2f" % (exp/n_pers))


if __name__ == "__main__":
    main()
