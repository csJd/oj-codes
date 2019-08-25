"""
因为公司有免费健身福利，快手程序员老铁们都很爱健身，而且他们健身时像工作
一样充满效率。
他们把健身过程神奇的简化了出来:健身有N种锻炼方式可选，器材可看成在一条
直线上。
每种锻炼方式距门口 Xi 米，因为有的器材上可以支持多种锻炼方式，因此有可能出
现两种锻炼方式的距离是一样的，即 Xa = Xb。
老铁们一进健身房门口就开启健身形态，每走1米，就能获得1点锻炼效果值，而每
种锻炼方式也有Ei的效果值，锻炼的过程就是从门口走到某种锻炼方式锻炼，然后
到下一个方式锻炼，最后返回门口的过程。需要注意的是，锻炼过程中老铁们不会
为了获得效果而刻意走回头路。
老铁们很想知道如果想选择某几种锻炼方式，怎样获得最大锻炼效果。

输入描述:
第一行N，表示锻炼方式的个数
第二行N个整数，表示每种锻炼方式距门口的距离
第三行N个整数，表示每种锻炼方式的效果值

输出描述:
N个整数，第k行表示选择k种锻炼方式时获得的最大锻炼效果


5
1 2 3 4 5
1 1 1 1 1

11
12
13
14
15
"""

from functools import cmp_to_key


# %0 Passed
def main():
    n = int(input())
    cost = list(map(int, input().split()))
    gain = list(map(int, input().split()))

    indices = list(range(n))

    def cmp(i, j):
        return gain[i] - gain[j] + 2 * (cost[i] - cost[j])
    indices.sort(key=cmp_to_key(cmp), reverse=True)

    for k in range(1, n+1):
        ans = 0
        max_cost = 0
        for ind in indices[:k]:
            max_cost = max(max_cost, cost[ind])
            ans += gain[ind]
        ans += (max_cost) * 2
        print(ans)

    pass


if __name__ == "__main__":
    main()
