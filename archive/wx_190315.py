# coding: utf-8

'''
Input:
输入为 n 个字符串 (n=1, 2, ..., 10), 每个字符串长度 <= 3
Output:
输出为各个字符串的字母拼接结果，输出顺序可颠倒

input: abc
output: a b c

input: cd ab
output: ca cb da db
'''


def dfs(str_list, pos, n, cur, res):
    if pos >= n:
        res.append(cur)
        return
    s = str_list[pos]
    for k in range(len(s)):
        dfs(str_list, pos+1, n, cur + s[k], res)


def main():
    lis = input().split()
    print(lis)
    n = len(lis)
    res = list()
    dfs(lis, 0, n, '', res)
    print(' '.join(res))


if __name__ == '__main__':
    main()
