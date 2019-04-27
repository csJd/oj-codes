'''
题目描述
给定一个长度为n的，仅包含0,1的数列。例如1,0,0,1,1,1,0,1
我们可以轻易算出，它的最长全1区间长度是3。从数组的第4个数到第6个数。
现在，你获得了k次可以将某个位置上的0变为1的机会，但你可以不用完你的所有机
会。
请你给出，你使用了你的变化机会后，这个数列的最长全1区间最大是多少。

输入描述:
输入第一行是2个整数n和k，代表数组长度和你的变化机会
输入第二行是n个整数，每个整数是0或1。代表初始数列
数据保证1<=n<=500000，0<=k<=500000

输出描述
输出包含一个整数，代表你的答案。

4 1
0 1 0 1
3

5 5
1 0 0 0 1
5
'''


# Wrong Answer
def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    length = len(arr)
    last = 0
    maxlen = 0
    if k >= length - sum(arr):
        maxlen = length
    for i in range(length):
        if arr[i] == 0:
            maxlen = max(maxlen, i-last-1)
            last = i
    maxlen = max(maxlen, length-last-1)
    print(maxlen)


if __name__ == "__main__":
    main()
