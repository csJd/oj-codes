"""
same as https://codeforces.com/problemset/problem/1189/B
solution https://luckyglass.github.io/2019/19July7thArt1/

2
5
17 6 17 11 17
3
1 2 4

YES
NO
"""


def main():
    # bug solution
    # hack case: [1, 1, 2, 2, 3]
    t = int(input())
    while t > 0:
        t -= 1
        n = int(input())
        arr = list(map(int, input().split()))
        arr.sort()

        mid = n // 2
        arr = arr[:mid] + arr[:mid-1:-1]
        for i in range(n):
            if arr[i] >= arr[i-1] + arr[(i+1) % n]:
                print("NO")
                break
        else:
            print("YES")


if __name__ == "__main__":
    main()
