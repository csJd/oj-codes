"""
拼接迷宫
题目描述：
构造一个迷宫是很麻烦的一件事情，因此有人提出了一种迷宫生成方法，与铺砖的方法类似，首先设计一个n*m的单位迷宫，然后就像铺砖一样，将这个单位迷宫复制拼接起来，如果能够通过这种方式生成的迷宫可以从起始位置通向无穷多的位置，那么我们认为这个单位迷宫是合法的（每个单位不可旋转）。

单位迷宫的表示包含三种符号,‘#’,‘.’和‘S’，其中‘#’代表墙，‘.’代表没有障碍物可以通过的，S则代表的是起始位置，当然迷宫是只有一个起点的，你可以任选一个单位迷宫的S位置作为起点，其他单位迷宫的S则视为可通行的。

输入
输入第一行包含一个正整数T，表示数据组数。(1<=T<=10)
接下来有T组输入，每组输入第一行是两个正整数n,m,表示单位迷宫是n行m列（1<=n,m<=300）。
之后n行每行是一个长度为m的字符串。如题所述，描述了一个单位迷宫。

输出
对于每组输入输出一行，如果这个单位迷宫是合法的，就输出“Yes”，否则就输出“No”。

样例输入
2
2 2
S#
#.
3 3
...
###
#S#

样例输出
No
Yes
"""


def main():
    # 9% AC
    direc = [(0, 1), (1, 0), (0, -1), (-1, 0)]

    n_cases = int(input())
    while n_cases > 0:
        n_cases -= 1
        n, m = map(int, input().split())
        graph = list()
        for i in range(n):
            graph.append(input()*2)
        graph *= 2

        n *= 2
        m *= 2

        cnt = 0
        vis = [[False] * m for k in range(n)]

        def dfs(i, j):
            nonlocal cnt
            if graph[i][j] == 'S':
                cnt += 1
            if cnt >= 2:
                return

            vis[i][j] = True
            for dx, dy in direc:
                r = i + dx
                c = j + dy
                if 0 <= r < n and 0 <= c < m and graph[r][c] != '#' and not vis[r][c]:
                    dfs(r, c)

        for i in range(n):
            for j in range(m):
                if cnt < 2 and graph[i][j] == 'S':
                    cnt = 0
                    vis = [[False] * m for k in range(n)]
                    dfs(i, j)

        print("Yes" if cnt >= 2 else "No")


if __name__ == "__main__":
    main()
