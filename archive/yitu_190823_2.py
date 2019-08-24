"""
题目描述
Po是个大胃王，他而且非常喜欢吃蛋糕吗，每当他经过一个地方的时候会忍不住买
下当地所有的蛋糕。有一次他收到朋友Pa的邀请去做客。已知Po目前在A市，Pa在
B市，Po要经过若干城市才能从到达B市，且他每经过一-个城市，就会把当地所有的
蛋糕都买下来。Po希望能尽快到达B市，且买尽可能多的蛋糕，他来找你帮忙，希
望你能给出方案。
已知总共有N个城市，每个城市分别有Qi个蛋糕，它们之间共有M条路连接，经过每
条路耗费的时间为Ti。
输入描述:
第一行输入N、M、S和D，N表示所有的城市数，M表示城市间的道路数，s表示出
发的A市，D表示需要到达的B市，
之后一行输入N个整数Qi,表示每个城市的蛋糕数，
之后M行，每行输入三个整数i、j和t，表示从城市i到城市j存在一条道路，通过
这条道路需要花费时间t。
2<=N<=10^4，1<=M<=10^6,1<=i,j,S,T<=N，1<=Qi,
t <= 10^6。
输出描述:
输出两个整数，total_ time和num, 分别表示到达B市需要的最少时间和在最少
时间下能够最多能够买到的蛋糕数。

4 5 1 4
10 20 30 40
1 2 2
1 3 3
2 3 2
3 4 3
2 4 4

6 80
"""


# 60% AC
def main():
    n, m, s, d = map(int, input().split())
    Q = list(map(int, input().split()))
    adj = [list() for i in range(n)]

    for i in range(m):
        u, v, t = map(int, input().split())
        adj[u-1].append((v-1, t))
        adj[v-1].append((u-1, t))

    inf = 1 << 63
    times = [inf] * n
    times[s-1] = 0

    cakes = [0] * n
    cakes[s-1] = Q[s-1]

    vis = [False] * n
    vis[s-1] = True

    def dijkstra():
        cur = s - 1
        for k in range(n-1):
            for v, t in adj[cur]:
                if (not vis[v]) and (
                    times[cur] + t < times[v] or
                    (times[cur] + t == times[v]
                     and cakes[cur] + Q[v] > cakes[v])
                ):
                    times[v] = times[cur] + t
                    cakes[v] = cakes[cur] + Q[v]

            min_d = inf
            for u in range(n):
                if (not vis[u]) and times[u] < min_d:
                    min_d = times[u]
                    cur = u
            vis[cur] = True
            if cur == d - 1:
                return times[cur], cakes[cur]

    total_time, num = dijkstra()
    print(total_time, num)


if __name__ == "__main__":
    main()
