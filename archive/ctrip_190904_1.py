"""
车辆时刻表分组
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
某车站为了方便管理，决定根据目的地以及出发时间的不同对车辆时刻表进行分组管理。要求：给定一个时刻表，同一个目的地的车辆必须分配在同一组内，分组不能打乱时刻表的车次顺序，即各个分组之间出发时间有序。请对时刻表尽可能多的分组，按出发时间早晚作为输出顺序。

输入
时刻表内容：aabbcddc，a,b,c,d为目的地，字母出现的先后顺序为出发时间的先后顺序

输出
输出各个分组的长度，以空格相隔，输出顺序与时刻表的出发顺序一致


样例输入
aabbcddc
样例输出
2,2,4

提示
aabbcddc 可分为aa,bb,cddc三组，目的地相同的车辆分配在了一组，同时，aa分组出发时间早于bb分组，bb分组早于cddc分组，所以输出结果为2，2，4。若分为一组，aabbcddc，则不满足题目中尽可能多的分组这一要求。输入不为空

"""

from collections import defaultdict


def main():
    cnt = defaultdict(int)
    buses = input()
    for x in buses:
        cnt[x] += 1

    n_buses = 0
    ans = list()
    group_cnt = defaultdict(int)
    for x in buses:
        group_cnt[x] += 1
        n_buses += 1
        for bus in group_cnt:
            if group_cnt[bus] != cnt[bus]:
                break
        else:
            group_cnt = defaultdict(int)
            ans.append(str(n_buses))
            n_buses = 0
    print(','.join(ans))


if __name__ == "__main__":
    main()
