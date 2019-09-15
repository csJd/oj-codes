"""
在《猫和老鼠》手游中，猫和老鼠都有很多种不同的知识卡，玩家可以消耗一定的知识点进行抽
卡，多次抽卡可能获得重复类型的知识卡，不同的知识卡可以给角色提供对应的被动技能。例如，
鼠的S级知识卡一无畏: 在营救队友之后，彼此可以获得短暂的无敌时间，足以让老鼠跑
到一个安全的位置;
猫的B级知识卡一踪: 每隔一 段时间，就能在小地图 上找到受伤的老鼠， 可以更好地进
行针对，打乱老鼠们的节奏。
有一天，玩家小U对玩家小S说:我已经进行过3次抽卡，并且从这3次抽卡中一共获得了无
畏、寻踪2种不同的知识卡，你能知道我有多少种抽卡顺序吗?”。小S摸了摸脑袋:“这可难不倒
我”，瞬间在纸上写出了可能的6种抽卡顺序:
无畏、无畏、寻踪
无畏、寻踪、无畏
寻踪、无畏、无畏
寻踪、寻踪、无畏
寻踪、无畏、寻踪
无畏、寻踪、寻踪
作为计算机专业毕业的小S补充道:“对于任意n次抽卡，从这n次抽卡获得了m种知识卡，我都能
很快帮你算出有多少种抽卡顺序~”，并运用熟练的编程技能很快地给出了正确答案。
你知道小 S 是怎么计算的吗?请编码实现对于不同的 n 和 m ,输出可能的抽卡顺序数。

输入描述:
输入包含两个整数 n 和 m (1<=m<=n<=100)，用空格分开，分别表示抽卡次数和获得的知识卡
种类数;

输出描述:
玩家可能的抽卡顺序数。

翻译：
n 个球 m 个盒子（球各不相同，盒子各不相同），每个盒子至少放一个球，共有多少种放法？
hint: 盒子相同时是第二类斯特林数 S(n, m) https://oi-wiki.org/math/stirling/#_2
"""

# use dp directly
n, m = (int(x) for x in input().split())

dp = [[0] * (m+1) for i in range(n+1)]
dp[0][0] = 1
for i in range(1, n+1):
    for j in range(1, m+1):
        # place the i-th ball into a box containing other balls or a empty box
        dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) * j

print(dp[n][m])


# use stirling number
# def stirling2(n, m):
#     dp = [[0] * (m+1) for i in range(n+1)]
#     dp[0][0] = 1
#     for i in range(1, n+1):
#         for j in range(1, m+1):
#             dp[i][j] = dp[i-1][j]*j + dp[i-1][j-1]
#     return dp[n][m]


# ans = 1
# for i in range(1, m+1):
#     ans *= i
# ans *= stirling2(n, m)
# print(ans)
