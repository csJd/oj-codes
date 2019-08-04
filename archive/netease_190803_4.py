"""
题目描述:
给定 01 序列 S，序列 S 是优秀的 01 序列，优秀的 01 序列定义如下:
1. 如果序列 S,T 是优秀的，则序列 S+T 是优秀的，"+" 被定义为按顺序连
接两个序列，即 "010" + "110" = "010110"。
2. 如果序列 S 是优秀的，则序列 rev(S) 也是优秀的。rev(S) 被定义为按
位翻转（0 变 1,1 变 0）序列 S，并删去前导零。
例如 rev("1100101") = "11010"。现在请你判断序列 T 是不是优秀的。

输入描述:
第一行数据组数 N，表示有 N 组数据。
每组数据的第一行是一个 01 序列，表示序列s。
第二行是另一个 01 序列，表示序列 T。
1 <= |S|,|T| <= 1000，S，T 不含前导零。

输出描述:
对于每组数据，一行输出 "YES" 或者 "NO"，表示序列 T 是不是优秀的。

2
1100
110011
1000
100001111
YES
NO

Solution: https://www.nowcoder.com/discuss/216237
"""


def rev(s):
    s = list(s)
    left = len(s)
    i = 0
    while i < len(s):
        if left == len(s) and s[i] == '1':
            i += 1
        else:
            if left == len(s):
                left = i
            s[i] = '1' if s[i] == '0' else '0'
            i += 1
    if left == len(s):
        return '0'
    return ''.join(s[left:])


def main():
    # not finished
    n_cases = int(input())
    while n_cases > 0:
        n_cases -= 1
        s = input().strip()
        t = input().strip()


if __name__ == "__main__":
    main()
    # print(rev("1100101"))
    # print(rev("11"))
