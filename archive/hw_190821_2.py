"""
[low, high) 范围内所有素数的十位数的和与个位数的和的最小值

151 160

8
"""

from bisect import bisect_left


def bf_solution():
    low, high = map(int, input().split())

    def isPrime(x):
        for i in range(2, x):
            if i * i > x:
                break
            if x % i == 0:
                return False
        return True

    a = 0
    b = 0
    for num in range(low, high):
        if isPrime(num):
            a += num//10 % 10
            b += num % 10

    print(min(a, b))


# euler sieve solution
def main():
    low, high = map(int, input().split())
    pme = list()

    def euler_sieve():
        vis = [False] * high
        for i in range(2, high):
            if not vis[i]:
                pme.append(i)
            for x in pme:
                if x * i >= high:
                    break
                vis[x*i] = True
                if i % x == 0:
                    break
    euler_sieve()

    a = 0
    b = 0
    pos = bisect_left(pme, low)
    while pos < len(pme):
        a += pme[pos] // 10 % 10
        b += pme[pos] % 10
        pos += 1
    print(min(a, b))


if __name__ == "__main__":
    main()
