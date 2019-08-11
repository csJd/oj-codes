"""
容量为 m 的水池有入水管和排水管，入水管每单位时间入水 m1，每 t1 时间改变状态（开/关）；排水管每单位时间排水 m2，每 t2 时间改变状态，问时刻 t 水池中的水量

5
10 2 1 5 2 5
10 2 10 5 2 5
10 2 3 5 2 5
100 100 3 4 4 3
10000 1000 10 5 5 3
"""


def main():
    n_cases = int(input())
    while n_cases > 0:
        n_cases -= 1
        m, t, m1, t1, m2, t2 = map(int, input().split())
        inp = out = False
        cur = 0
        for i in range(t):
            if i % t1 == 0:
                inp = not inp
            if i % t2 == 0:
                out = not out
            if inp:
                cur += m1
            if out:
                cur -= m2
            if cur < 0:
                cur = 0
            if cur > m:
                cur = m
        print(cur)


if __name__ == "__main__":
    main()
