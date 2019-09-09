"""蠕虫的传播
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
在节点网络中，只有当 graph[i][j] = 1 时，每个节点 i 能够直接连接到另一个节点 j。

一些节点 initial 最初被蠕虫感染。只要两个节点直接连接，且其中至少一个节点受到蠕虫的感染，那么两个节点都将被蠕虫感染。蠕虫的传播将继续，直到没有更多的节点可以被这种方式感染。
假设 M(initial) 是在蠕虫停止传播之后，整个网络中感染蠕虫的最终节点数。
我们可以从初始列表中删除一个节点。如果移除这一节点将最小化 M(initial)， 则返回该节点。如果有多个节点满足条件，就返回索引最小的节点。
请注意，如果某个节点已从受感染节点的列表 initial 中删除，它以后可能仍然因蠕虫传播而受到感染。

输入
第一行：节点网络的行数
中间行：节点网络graph
最后一行：受感染节点的列表initial

输出
输出能够使M最小化的节点的索引。

样例输入
3
1 1 0
1 1 0
0 0 1
0 1
样例输出
0

提示
1 < graph.length = graph[0].length <= 300
0 <= graph[i][j] == graph[j][i] <= 1
graph[i][i] = 1
1 <= initial.length < graph.length
0 <= initial[i] < graph.length
"""

par = [-1] * 301


def find(u):
    ru = u
    while par[ru] >= 0:
        ru = par[ru]
    while u != ru:
        u, par[u] = par[u], ru
    return ru


def union(u, v):
    if (u == v):
        return
    ru = find(u)
    rv = find(v)
    num = par[ru] + par[rv]
    if par[ru] < par[rv]:
        par[rv], par[ru] = ru, num
    else:
        par[ru], par[rv] = rv, num


def main():
    n = int(input())
    grid = list()
    for i in range(n):
        row = list(map(int, input().split()))
        grid.append(row)

    initial = list(map(int, input().split()))

    minv = 0
    ans = 0
    for ind, pos in enumerate(initial):
        global par
        if len(initial) == 1:
            break
        par = [-1] * 301
        first = initial[:pos] + initial[pos+1:]

        for u in range(n):
            for v in range(n):
                if grid[u][v] == 1:
                    union(u, v)

        for u in first:
            for v in first:
                union(u, v)

        r = find(first[0])
        if par[r] < minv:
            minv = par[r]
            ans = ind

    print(ans)


if __name__ == "__main__":
    main()
