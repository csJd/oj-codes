"""
输入一个数组，每次可以选择一个数将其递增 1，求使得数组中每个值都唯一需要的最小操作次数

1,2,2
1
"""


def main():
    arr = list(map(int, input().strip().split(',')))
    arr.sort()
    ans = 0
    length = len(arr)
    for i in range(1, length):
        if arr[i] <= arr[i-1]:
            ans += arr[i-1] - arr[i] + 1
            arr[i] = arr[i-1] + 1
    print(ans)


if __name__ == "__main__":
    main()
