"""
7 4
1110100110

1001010


6 2
1110001

101111
"""


def main():
    n, k = map(int, input().split())
    length = n+k-1
    code = input()
    cur = '0'
    ans = []
    for i in range(length-1, length-n-1, -1):
        if i < length - k:
            cur = '0' if cur == ans[-k] else '1'
        if cur == code[i]:
            ans.append('0')
        else:
            ans.append('1')
        cur = '0' if cur == ans[-1] else '1'
    ans.reverse()
    print("".join(ans))


if __name__ == "__main__":
    main()
