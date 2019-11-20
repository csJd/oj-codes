"""
提莫攻击
时间限制：C/C++语言 1000MS；其他语言 3000MS

题目描述：
在《英雄联盟》的世界中，有一个叫“提莫”的英雄，他的攻击可以让敌方英雄进入中毒状态。现在，给出提莫对艾希的攻击时间序列和提莫攻击的中毒持续时间，你需要输出艾希的中毒状态总时长。
你可以认为提莫在给定的时间点进行攻击，并立即使艾希处于中毒状态。

输入
输入一行：攻击的时间序列（时间点间空格隔开）和中毒持续时间
时间序列和中毒持续时间间逗号隔开

输出
中毒总时间


样例输入
1 2, 2
样例输出
3
"""


def main():
    sarr, ssep = input().split(',')
    sep = int(ssep)
    arr = list(map(int, sarr.split(' ')))
    arr.sort()

    ans = 0
    cur = arr[0] if len(arr) > 0 else arr[0]
    last = cur
    for t in arr:
        if t > cur:
            ans += cur - last
        else:
            ans += t - last
        cur = t + sep
        last = t
    ans += cur - last

    print(ans)


if __name__ == "__main__":
    main()
