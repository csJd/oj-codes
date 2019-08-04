"""
输入 1...n 组成的集合中字典序为 P 的一个排列，输出字典序为倒数 P 的排列
"""


def main():
    n = int(input())
    arr = list(map(int, input().split()))
    for i in range(n):
        arr[i] = n+1-arr[i]
    print(' '.join(map(str, arr)))
    pass


if __name__ == "__main__":
    main()
