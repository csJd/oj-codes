"""
试题描述:
小张想要购买一本总价为M的书籍，他选择出售一些其他的书籍来购买这本书。 已知
出售其他的书籍的价格分别为W1、W2.. .Wn,请你计算一下有 多少种出售方法，可以
刚好购买这本书，并分别输出书的价格。(假设所需 购买的书籍和需要出售的书籍的
价格都是正整数)

输入:输入需要出售书籍的总数 n,每一本书的价格用数组 w 中每一个元素表示，需要
购买的书籍的价格为 m
buybook(int w[, int m,int n)
输出:输出每一-组符合 条件的解

1,2,3,4,8,5,10,20 10 8
>>
1,2,3,4
1,4,5
2,8
"""


sw, sm, sn = input().split()
w = [int(x) for x in sw.split(',')]
m, n = int(sm), int(sn)

ans = list()


def dfs(pos, cur, sum):
    if sum == 0:
        ans.append(cur)
        return
    if pos >= n:
        return

    if sum >= w[pos]:
        dfs(pos+1, cur+[w[pos]], sum-w[pos])
    dfs(pos+1, cur, sum)


dfs(0, [], m)
for res in ans:
    print(','.join(map(str, res)))
