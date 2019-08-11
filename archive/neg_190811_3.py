"""
你可以最多改变两个大写字母，使得字符串所包含的连续的 N 串的长度最长，求最长长度

5
NNTN
NNNNGGNNNN
NGNNNNGNNNNNNNNSNNNN
TNT
T

4
10
18
3
1
"""


def main():
    # two pointer solution
    n_cases = int(input())
    while n_cases > 0:
        n_cases -= 1
        s = input().strip()
        length = len(s)

        le = ri = 0
        max_length = 0
        cnt = 0  # the count of non-'N' in current [le, ri] window
        while ri < length:
            if cnt > 2:
                if s[le] != 'N':
                    cnt -= 1
                le += 1
            else:
                if s[ri] != 'N':
                    cnt += 1
                ri += 1
                max_length = max(max_length, ri-le)

        print(max_length)


def bad_main():
    n_cases = int(input())
    while n_cases > 0:
        n_cases -= 1
        s = input().strip()
        length = len(s)

        cnt = s.count('N')

        longest = 0
        if cnt == 0:
            longest = min(2, length)

        for i, c in enumerate(s):
            if c != 'N':
                continue
            brk = 0
            for j in range(i, length):
                if s[j] != 'N':
                    if brk > 1:
                        longest = max(longest, j-i)
                        break
                    brk += 1
                if j == length - 1:
                    longest = max(longest, min(length, j-i+3-brk))
        print(longest)


if __name__ == "__main__":
    main()
