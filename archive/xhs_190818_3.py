"""
击败魔物
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
薯队长来到了迷宫的尽头，面前出现了N只魔物，Hi表示第i只魔物的血量，薯队长需要在T个回合内击败所有魔物才能获胜。每个回合薯队长可以选择物理攻击一只魔物，对其造成1点伤害（物理攻击次数无上限）;  或者消耗1点法力释放必杀技对其造成固定X点伤害（薯队长开始拥有M点法力）。问X至少多大，薯队长才有机会获胜；如果无论如何都无法在T回合内获胜，则输出-1

输入
第一行三个整数分别表示：N T M
第二行有N个整数：H1 H2 H3 … HN

对于50%的数据：
0 < N < 10^3
0 < T < 10^3
0 <= M <= T
0 < Hi < 10^4

对于100%的数据
0 < N < 10^5
0 < T < 10^7
0 <= M <= T
0 < Hi < 10^7

输出
输出一个整数，表示必杀技一次最少造成多少固定伤害

样例输入
3 4 3
5 2 1
样例输出
3

提示
第1回合消耗1点法力，对魔物1造成3点伤害。
第2回合消耗1点法力，对魔物1造成3点伤害，击杀。
第3回合消耗1点法力，对魔物2造成3点伤害，击杀。
第4回合攻击魔物3造成1点伤害，击杀。
"""


def can_win(arr, n, t, m, x):
    tmp = arr.copy()
    n_turns = 0
    for i in range(n):
        times = tmp[i] // x
        if m >= times:
            tmp[i] %= x
            m -= times
            n_turns += times
        else:
            tmp[i] -= m*x
            n_turns += m
            m = 0
            break

    # has mp left
    if m > 0:
        tmp.sort(reverse=True)
    for val in tmp:
        if m > 0:
            m -= 1
            n_turns += 1
        else:
            n_turns += val

    return n_turns <= t


def main():
    n, t, m = map(int, input().split())
    arr = list(map(int, input().split()))

    le = 1
    ri = max(arr)
    if not can_win(arr, n, t, m, ri):
        print(-1)
        return

    while le <= ri:
        mid = (le + ri) >> 1
        if can_win(arr, n, t, m, mid):
            ri = mid - 1
        else:
            le = mid + 1
    print(ri+1)


if __name__ == "__main__":
    main()
