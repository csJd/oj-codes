"""
多多鸡在公司负责一个分布式任务执行平台的维护。夏天到
了，平台的服务器都因中署而无法执行任务了。所以多多鸡必
须自己手动来执行每个任务!
现在一共有 N 个待执行的任务，每个任务多多鸡需要 Pi 的
时间完成执行。同时，任务之间可能会有一些依赖关系。比如
任务 1 可能依赖任务 2 和任务 3，那么任务 1 必须在任务
2 和任务 3 都执行完成后才能执行。
多多鸡只有一个人，所以同时只能执行一个任务，并且在任务
完成之前不能暂停切换去执行其他任务。为了提升平台用户的,
使用体验，多多鸡希望最小化任务的平均返回时长。一个任务
的返回时长定义为任务执行完成时刻减去平台接收到该任务的
时刻。在零时间，所有 N 个任务都已经被平台接收。
请你帮多多鸡安排一下 任务执行顺序,使得平均返回时长最
小。

输入描述：
第一行包含 2 个正整数 N, M, 分別表示任努数量以及 M 个
任务依赖关系。
第二行包含 N 个正整数，第 i (1 <= i <= N) 个数表示
第 i 个任努的趾理吋囘 Pi
接下来的 M 行，毎行表示一个任努依頼美系。毎行包含 2 个
整数 Ai(1 <= Ai <= N)、Bi(1<=Bi<=N)，表示第
Bi个任努依頼于第Ai个任努。数据保証不会出現循坏依頼
的情况。
数据范圃:
1 <= N <= 1000
1 <= M <= 50000
1 <= Pi <= 10000

输出描述：
输出一行，包含 N 个整数（两两之间用一个空格符分隔），其
中第 i （1 <= i <= N）个整数表示多多鸡执行的第 i 个
任务的编号。若有多种可行方案，则输出字典序最小（优先执行
编号较小的任务）的方案。

5 6
1 2 1 1 1
1 2
1 3
1 4
2 5
3 5
4 5

1 3 4 2 5

100%
"""


def main():
    """ main """
    n, m = map(int, input().split())
    p = [0] + list(map(int, input().split()))

    dep = [[] for i in range(n + 1)]
    dep_cnt = [0] * (n+1)
    for i in range(m):
        a, b = map(int, input().split())
        dep[a].append(b)
        dep_cnt[b] += 1

    queue = []
    for i in range(1, n+1):
        if dep_cnt[i] == 0:
            queue.append(i)
    queue = list(sorted(queue, key=lambda x: p[x]))

    result = []
    while queue:
        cur = queue.pop(0)
        result.append(cur)
        for i in dep[cur]:
            dep_cnt[i] -= 1
            if dep_cnt[i] == 0:
                queue.append(i)
        queue = list(sorted(queue, key=lambda x: (p[x], x)))

    print(' '.join([str(x) for x in result]))


if __name__ == "__main__":
    main()
