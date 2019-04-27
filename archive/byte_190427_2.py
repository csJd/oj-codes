'''
题目描述
小包最近迷上了一款叫做雀魂的麻将游戏，但是这个游戏规则太复杂，小包玩了几
个月了还是输多赢少。
于是生气的小包根据游戏简化了一下规则发明了一种新的麻将，只留下一种花色，
并且去除了一些特殊和牌方式(例如七对子等)，具体的规则如下:
1.总共有36张牌，每张牌是1~9。每个数字4张牌。
2.你手里有其中的14张牌，如果这14张牌满足如下条件，即算作和牌
  ● 14张牌中有2张相同数字的牌，称为雀头。
  ● 除去上述2张牌，剩下12张牌可以组成4个顺子或刻子。顺子的意思是递增的连
    续3个数字牌(例如234,567等) ，刻子的意思是相同数字的3个数字牌(例如
    111,777)
例如:
11122266677799 可以组成1,2,6,7的4个刻子和9的雀头，可以和牌
11112233567789 用1做雀头，组123,123,567,789的四个顺子，可以和牌
11122233356779 无论用1 2 3 7哪个做雀头，都无法组成和牌的条件。
现在，小包从36张牌中抽取了13张牌，他想知道在剩下的23张牌中，再取一张牌，
取到哪几种数字牌可以和牌。

输入描述:
输入只有一行，包含13个数字，用空格分隔，每个数字在1~9之间，数据保证同
种数字最多出现4次。

输出描述:
输出同样是一行，包含1个或以上的数字。代表他再取到哪些牌可以和牌。若满足
条件的有多种牌，请按从小到大的顺序输出。若没有满足条件的牌，请输出一个
数字0

1 1 1 2 2 2 5 5 5 6 6 6 9
9

1 1 1 1 2 2 3 3 5 6 7 8 9
4 7

1 1 1 2 2 2 3 3 3 5 7 7 9
0
'''


def check(arr):
    cnt = [arr.count(i) for i in range(10)]
    for i in range(1, 10):
        if cnt[i] >= 2:
            cnt[i] -= 2
            if check_cnt(cnt):
                return True
            cnt[i] += 2
    return False


def check_cnt(cnt):
    if sum(cnt) == 0:
        return True
    if sum(cnt) < 3:
        return False
    tcnt = cnt.copy()
    for j in range(1, 8):
        cnt = tcnt.copy()
        if cnt[j] > 0 and cnt[j+1] > 0 and cnt[j+2] > 0:
            cnt[j] -= 1
            cnt[j+1] -= 1
            cnt[j+2] -= 1
            if check_cnt(cnt):
                return True

    for j in range(1, 10):
        cnt = tcnt.copy()
        for i in range(10):
            if cnt[i] > 2:
                cnt[i] -= 3
                if check_cnt(cnt):
                    return True

    return False


def main():
    remains = [0] + [4 for i in range(9)]
    arr = list(map(int, input().split()))
    for i in arr:
        remains[i] -= 1

    res = []
    for i in range(10):
        if remains[i] and (check([i] + arr)):
            res.append(i)
    if len(res) == 0:
        res = [0]
    print(*res)


if __name__ == "__main__":
    main()
