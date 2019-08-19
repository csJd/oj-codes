"""
求 arr[j] - arr[i] 的最大值， j > i

1 3 2 4 5 0 2 3 7
7
"""


def main():
    arr = list(map(int, input().split()))
    i = j = 0
    ans = 0
    while j < len(arr):
        if arr[j] <= arr[i]:
            i = j
        ans = max(ans, arr[j] - arr[i])
        j += 1
    print(ans)


if __name__ == "__main__":
    main()
