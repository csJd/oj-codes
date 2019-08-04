"""
same as https://codeforces.com/problemset/problem/1174/B

4
7 3 5 1

7 3 5 1


10
53941 38641 31525 75864 29026 12199 83522 58200 64784 80987

12199 29026 31525 38641 53941 58200 64784 75864 80987 83522
"""


def main():
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n-1):
        if (a[i] + a[i+1]) % 2 == 1:
            a.sort()
            break
    print(' '.join(map(str, a)))


if __name__ == "__main__":
    main()
