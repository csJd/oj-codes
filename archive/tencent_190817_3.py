"""
3 10
2 5 3
2 1 3

4
"""


def main():
    n, m = map(int, input().split())
    arr_w = list(map(int, input().split()))
    arr_v = list(map(int, input().split()))

    def money_ok(num):
        cost = 0
        for w, v in zip(arr_w, arr_v):
            if w < num:
                cost += (num - w) * v
        return cost <= m

    le = 0
    ri = 10 ** 13
    while le <= ri:
        mid = (le+ri) >> 1
        if money_ok(mid):
            le = mid + 1
        else:
            ri = mid - 1
    print(max(0, le - 1))


if __name__ == "__main__":
    main()
