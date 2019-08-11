"""
1
5
8 3 5 7 2

3
"""


def main():
    n_cases = int(input())
    while n_cases > 0:
        n_cases -= 1
        n = int(input())
        arr = map(int, input().split())
        classes = set()
        for num in arr:
            cnt = 0
            while num:
                if num & 1:
                    cnt += 1
                num >>= 1
            classes.add(cnt)

        print(len(classes))


if __name__ == "__main__":
    main()
