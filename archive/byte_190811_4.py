"""
题目描述
小明练习跑步,他家附近的街道是棵树, 这棵树上的点按 1 到 n 标号,任意两点间互相可达,并且
有且仅有一条路,每条路的距离都是 1, 需要在树上找一条路来跑,小明对 3 很感兴趣,所以他想
知道所有跑道距离和 %3 = 0, 1, 2 的道路总长度一共各有多长。
即树上任意两点间距离 %3=k 的距离和。

输入描述:
第一行一个 n,点数 n<=1e5
接下来 n-1 行每行 u, v 一条无向边

输出描述:
一行3个整数，分别代表 %3 = 0, 1, 2 的两点距离的距离和，结果取模1e9+7

3
1 2
2 3

0 2 2
"""


def main():
    # 30% passed TLE solution
    MOD = 10 ** 9 + 7

    n = int(input())
    d = [[n] * (n + 1) for i in range(n+1)]

    for i in range(n-1):
        u, v = map(int, input().split())
        d[u][v] = d[v][u] = 1

    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                if i != j:
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j])

    ans = [0]*3
    for i in range(1, n+1):
        for j in range(i+1, n+1):
            ans[d[i][j] % 3] += d[i][j]

    for i in range(3):
        ans[i] %= MOD

    print(' '.join(map(str, ans)))


if __name__ == "__main__":
    main()
