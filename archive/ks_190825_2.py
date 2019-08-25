"""
abcabcbb

3
"""


def main():
    s = input()
    length = len(s)
    le = ri = 0
    window = set()
    ans = 0
    while ri < length:
        while ri < length and s[ri] in window:
            window.remove(s[le])
            le += 1
        window.add(s[ri])
        ri += 1
        ans = max(ans, len(window))

    print(ans)


if __name__ == "__main__":
    main()
