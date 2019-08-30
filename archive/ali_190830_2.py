"""
每天都有无数的人跟我厂出品的天猫精灵对话，天猫精灵为人类跟他说的每句话都打上了一个意图标签，一个人的所有对话就
是这些意图标签组成的序列，这个序列里面的子序列就是段对话， 意图有直天气者温度查股票、 放音乐、 讲笑话等等。
最近天猫精灵灵光闪， 想研究下人类的对话，看看人们都喜欢怎么和它说话，比如有的人喜欢先问天气，再问股票，再让它
讲个笑话，再放首歌，有的人喜欢问了天气之后再问空气质量，然后再问下明天的天气，还有的人喜欢先听听歌，然后叫出租
车去上班等等。天猫精灵要找出人们普遍的规律，分析出大家般都喜欢怎么和他说话。 那么首先天猫精灵必须先解决个问
题，就是给定两个用户的意图序列，找出相似(编辑距离<=阈值)的子意图序列的pair,并且每个子意图序列满足定的长
度要求(长度必须在闭区间(minSeqL en, maxSeqLen]内)，一个子序列可重复出现在多个par中比如如下就是满足长度要
求(长度区间[5, 8)的两个相似(编辑距离为1,小于等于阈值2)的子意图序列pair:
A: weather, joke, music, stock, joke, joke, news
B: weather, joke, music, stock, joke, joke, texi
那么现在你可以帮天猫精灵完成这个任务吗?

输入数据包括 5 行：
第一行: 1 个数字，编辑距离阈值
第二行: 1 个数字，最小的序列长度
第三行: 1 个数字，最大的序列长度
第四行: 用户A的意图序列，英文逗号分隔
第五行: 用户B的意图序列，英文逗号分隔

输出：
一j个数字，满足条件的意图序列的 pair 的个数


1
3
5
weather,joke,music,stock,joke,news,taxi,temperature,pm2.5
joke,music,news,stock,joke,joke,news,taxi

14
"""


def edit_distance(arr1, arr2):
    # dp[i][j] -> minDistance(arr1[:i], arr2[:j])
    len1, len2 = len(arr1), len(arr2)
    dp = [[0] * (len2+1) for i in range(2)]  # 2 * (len2+1) array

    for j in range(len2+1):
        dp[0][j] = j

    for i in range(1, len1+1):
        cur = i % 2
        dp[cur][0] = i
        for j in range(1, len2+1):
            if arr1[i-1] == arr2[j-1]:
                dp[cur][j] = dp[cur-1][j-1]
            else:
                # min(remove, insert, replace)
                dp[cur][j] = min(dp[cur-1][j], dp[cur]
                                 [j-1], dp[cur-1][j-1]) + 1

    return dp[len1 % 2][len2]


def main():
    k = int(input())
    minl = int(input())
    maxl = int(input())

    arr1 = input().split(',')
    arr2 = input().split(',')
    l1 = len(arr1)
    l2 = len(arr2)

    ans = 0
    for lsub1 in range(minl, maxl+1):
        for lsub2 in range(minl, maxl+1):
            for i in range(l1 - lsub1 + 1):
                for j in range(l2 - lsub2 + 1):
                    if edit_distance(arr1[i:i+lsub1], arr2[j:j+lsub2]) <= k:
                        ans += 1
    print(ans)


if __name__ == "__main__":
    main()
