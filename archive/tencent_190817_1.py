"""
7 3
1 2 6 1 1 7 1

3
"""


def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    wind_sum = sum(arr[:k])
    min_sum = wind_sum
    pos = 0
    for i in range(k, n):
        wind_sum = wind_sum - arr[i-k] + arr[i]
        if wind_sum < min_sum:
            min_sum = wind_sum
            pos = i-k+2
    print(pos)


if __name__ == "__main__":
    main()
