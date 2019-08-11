"""
3
5 0
6 0
7 0
59
6 59

6 0
"""


def main():
    # 80% passed
    n = int(input())
    nz = list()
    for i in range(n):
        nz.append(tuple(map(int, input().split())))

    x = int(input())
    t_class = tuple(map(int, input().split()))

    nz.sort()
    ans = None
    for tup in nz:
        gap = (t_class[0] - tup[0]) * 60 + (t_class[1] - tup[1])
        if gap >= x:
            ans = tup

    if not ans:
        print(nz[0][0], nz[0][1])
    else:
        print(ans[0], ans[1])


if __name__ == "__main__":
    main()
