"""
题目描述
现在有一一个数列A(a1, a2, a3, .. an)，对于这个数列，你仅可以通过一种操作来改变
它:选择任意两个数，将其从数列中删除，并将这两个数之和作为-个新的元素加
在数列末尾。
现在的问题是，在操作至多k次的情况下，数列中能被3整除的数最多有多少个。
输入描述:
第一行输入为N、K, N表示数列长度，K表示最多允许操作K次，1 <= N,K <= 10^4。
第二行输入为N个整数ai,表示序列，1 <= ai <= 10^6。
输出描述:
输出一个整数，表示在操作不超过k次的情况下，数列中被3整除的数最多的个数
示例1输入输出示例仅供调试，后台判题数据一般不包含 示例

5 1
3 1 2 3 1

3
"""


def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    cnt = [0] * 3
    for x in arr:
        cnt[x % 3] += 1

    ans = min(k, cnt[1], cnt[2])
    k -= ans
    cnt[1] -= ans
    cnt[2] -= ans
    ans += cnt[0]
    ans += min(k//2, cnt[1]//2, cnt[2]//2)

    print(ans)


if __name__ == "__main__":
    main()
