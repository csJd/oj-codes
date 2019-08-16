"""
给定一个字符串，请你找出其中不含有重复字符的最长子串 。

输入：原始字符串
输出：最长子串

input: abcabcaa
output: abc
input: ddddddd
output: d
input: skkwek
output: kwe
"""

s = input()
length = len(s)

le = ri = 0
window = set()
ans = [0, 0]
while ri < length:
    while ri < length and s[ri] in window:
        window.remove(s[le])
        le += 1
    window.add(s[ri])
    ri += 1
    if len(window) > ans[1] - ans[0] + 1:
        ans[0], ans[1] = le, ri

print(s[ans[0]:ans[1]+1])
