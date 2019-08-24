"""
某市新建了一条N个站的单向地铁(0,1 2...N-1,第i站和第i+1站相邻)， 对于每个乘
客，假设从第S站上车，在第T站下车，需要支付(T-S)元。目前地铁公司准备通过车
站的进出人数统计应该收取的总车费，用于验证收费系统。现在这个计算总车费的
任务就交给了你。

输入描述:
第一行输入为N,表示有N个车站。
第二行输入为N个整数ai,表示第i-1个车站有ai个人进入
第三行输入为N个整数bi，表示第i-1个车站有b;个人离开
输出描述:
输出一个整数sum,表示总车费

3
1 2 0
0 0 3

4
"""

if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    length = len(a)
    ans = 0
    in_train = 0
    for i in range(length):
        in_train += a[i]
        in_train -= b[i]
        ans += in_train
    print(ans)
