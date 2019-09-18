"""
跳跃递推
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
很多数列都是递推形成的，现在给出一个序列的前四项，a[1],a[2],a[3],a[4],已知递推式是a[n]=a[n-1]+a[n-3]+a[n-4]。请你求出第n项的值。

输入
输入仅一行，包含4个正整数a[1],a[2],a[3],a[4]及n。
输出
输出仅包含一个正整数，即a[n],但是由于这个数可能非常大，所以请输出答案对10^9+7取模的结果。

样例输入
1 2 3 4 20
样例输出
9790
"""

MOD = int(1e9+7)


def matmul(mata, matb):
    n = len(mata)
    ret = [[0] * n for i in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                ret[i][j] += mata[i][k] * matb[k][j]
            ret[i][j] %= MOD
    return ret


def matpow(mat, k):
    n = len(mat)
    ans = [[1 if i == j else 0 for j in range(n)] for i in range(n)]
    while k:
        if k & 1:
            ans = matmul(ans, mat)
        k >>= 1
        mat = matmul(mat, mat)
    return ans


def main():
    # mat x [a(n-4); a(n-3); a(n-2); a(n-1)]
    #     = [a(n-3); a(n-2); a(n-1); a(n)]
    mat = [
        [0, 1, 0, 0],
        [0, 0, 1, 0],
        [0, 0, 0, 1],
        [1, 1, 0, 1]
    ]
    arr = list(map(int, input().split()))
    n = arr.pop()

    mat = matpow(mat, n-1)
    res = [0] * 4
    for i in range(4):
        for j in range(4):
            res[i] += mat[i][j] * arr[j]
        res[i] %= MOD
    ans = res[0]
    print(ans)
    brute_force(arr, n)


def brute_force(arr, n):
    i = 4
    while i < n:
        pos = i % 4
        arr[pos] = (arr[pos-1] + arr[pos-3] + arr[pos-4]) % MOD
        i += 1
    print(arr[(n-1) % 4])


if __name__ == "__main__":
    main()
