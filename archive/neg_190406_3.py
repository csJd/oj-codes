"""
题目描述：n 个 电池， m 条电线 (电线是单向的！) ， 电源连着电池 b， 电源功率为 e
某个电池充满电后通向其的功率会平均分往所连的电池
输入 n 个电池的容量
输出每个电池充满电所需时间

2
6 6 1 2
4 2 4 2 2 20
1 2
1 3
2 4
3 5
4 6
5 6
2 0 2 1
10 10

2.0000 4.0000 6.0000 6.0000 8.0000 17.0000
-1.0000 10.0000
"""

T = int(input())
for case in range(T):
    n, m, b, e = map(int, input().split())
    remain = list(map(int, input().split()))
    time_spent = [0 for i in range(n)]
    edge = [[] for i in range(n)]
    for k in range(m):
        st, ed = map(int, input().split())
        st -= 1
        ed -= 1
        edge[st].append(ed)
        # edge[ed].append(st)
    b -= 1

    charging = {b: e}
    while len(charging) > 0:
        pos = list(charging.keys())[0]
        power = charging.pop(pos)
        charge_time = remain[pos] / power
        time_spent[pos] += charge_time
        remain[pos] = 0

        for ind in range(n):
            if remain[ind] == 0:
                continue
            time_spent[ind] += charge_time
            if ind in charging:
                power = charging[ind]
                remain[ind] -= power * charge_time

        if len(edge[pos]) == 0:
            continue
        add_power = power / len(edge[pos])
        for ed in edge[pos]:
            if ed not in charging:
                charging[ed] = add_power
            else:
                charging.pop(ind)
                charging[ind] = power + add_power

        charging = dict(
            sorted(charging.items(), key=lambda tup: remain[tup[0]]/tup[1]))

    ret = []
    for i in range(n):
        if remain[i] == 0:
            ret.append(time_spent[i])
        else:
            ret.append(-1)

    print(*ret)
