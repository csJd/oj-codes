"""
重复子串模式
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
给定一个非空字符串（只包含小写英文字母，长度不超过1000），判断其是否可以通过自身子串重复若干次构成。

要求：利用KMP算法进行解题。

输入
测试用例有多行数据，对于每行：

是一个长度大于1的字符串，长度不超过1000。

输出
对于每一个字符串，输出一行True or False，判断当前字符串是否可以通过自身子串重复若干次构成。


样例输入
abdabcabdab
abdabcabdabc
样例输出
False
True
"""

import sys


def get_next(p):
    """ nex[i] 为子串 p[:i] 的最长相同前缀后缀长度
    """

    lp = len(p)
    nex = [0] * (lp+1)
    i = 0
    j = nex[0] = -1
    while i < lp:
        if j == -1 or p[i] == p[j]:
            nex[i+1] = j + 1
        else:
            j = nex[j]
        i += 1
        j += 1
    return nex


def kmp(s, p):
    cnt = 0

    lp = len(p)
    ls = len(s)
    nex = get_next(p)

    i = j = 0
    while i < ls:
        if j == -1 or s[i] == p[j]:
            i += 1
            j += 1
            if (j == lp):
                cnt += 1
                j = nex[j]
        else:
            j = nex[j]

    return cnt


def main():
    for line in sys.stdin:
        s = line.strip()
        length = len(s)
        nex = get_next(s)
        rep_len = len(s) - nex[-1]
        if rep_len < length and\
                length % rep_len == 0 and\
                s[:rep_len] * (length // rep_len) == s:
            print("True")
        else:
            print("False")


if __name__ == "__main__":
    main()
