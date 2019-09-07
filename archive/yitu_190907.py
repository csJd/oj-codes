"""
要求完成一个函数
函数的输入是一个 (n x m) 的 2 维的矩阵
矩阵中的元素都是 int
每个元素可以和上下左右 4 个方向的其他元素连接成路径
需要返回的是 [矩阵中最长递增路径的长度]

123
456
789 -> 5

345
216
987 -> 9
"""


matrix = [[3, 4, 5], [2, 1, 6], [9, 8, 7]]
n, m = 3, 3
dp = [[0] * m for i in range(n)]
dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]


def dfs(i, j):
    if dp[i][j] > 0:
        return dp[i][j]
    length = 1
    for d in range(4):
        r = i + dx[d]
        c = j + dy[d]
        if 0 <= r < n and 0 <= c < m and matrix[i][j] > matrix[r][c]:
            length = max(length, dfs(r, c) + 1)  # length cannot be dp[i][j]
    dp[i][j] = length
    return dp[i][j]


def main():
    maxl = 0
    for i in range(n):
        for j in range(m):
            if dfs(i, j) > maxl:
                maxl = dfs(i, j)
    print(maxl)


if __name__ == "__main__":
    main()

# 题2 抛硬币直到正面朝上，求抛硬币次数的期望，口头说答案
