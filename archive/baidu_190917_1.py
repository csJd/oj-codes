"""
定点射门
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
在一档综艺节目中，有一个定点射门的游戏，在一条直线上有n个球门区域，这些球门的大小并不一样，用形如“a b”的方式表示，球门区域是从a坐标到b坐标的区域，另外在距离球门所在直线不远处的平行轴处，有若干个摆放好的足球，由于参加综艺的人并不是专业运动员，因此只会将该直线a坐标处的足球踢到另一条直线的a坐标处。

球门可能会有重合，对于任何一个重合的位置，你可以任选一个球门踢入。只要有一个球门内有进球，就可以加一分，这位选手最多可以得多少分。

一颗球不可以在两个球门中重复计数，门柱等问题忽略不计。

输入
输入第一行仅包含两个正整数n,m,表示有n个球门，m颗球。
接下来n行，每行有两个正整数a,b，表示球门的范围。(1<=a,b<=1000)
再接下来m行，每行有一个正整数x，表示球所在的坐标。(1<=x<=1000)

输出
输出包含一个正整数，表示最大得分


样例输入
3 3
1 5
2 6
7 8
2
4
8
样例输出
3
"""


def main():
    all_goals = list()
    n, m = map(int, input().split())
    for i in range(n):
        a, b = map(int, input().split())
        all_goals.append((a, b))
    balls = [int(input()) for j in range(m)]

    # sorting goals accoroding to left position
    all_goals.sort(key=lambda x: x[0])
    reach = 0
    goals = []
    for goal in all_goals:
        if goal[1] > reach:
            reach = goal[1]
            goals.append(goal)

    balls.sort()
    i, j = 0, 0
    score = 0
    while i < len(goals) and j < m:
        if balls[j] > goals[i][1]:
            i += 1
        elif balls[j] >= goals[i][0]:
            score += 1
            j += 1
        else:  # balls[j] < goals[i][0]
            j += 1
    print(score)


if __name__ == "__main__":
    main()
