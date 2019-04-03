'''
合法字符串由字母或者数字组成
(1)输出合法字符串并去重
(2)输出所有非法字符串
(3)对结果1的去重合法字符串循环左移10次
(4)对结果3合法字符串字符串排序，按ASCII表字符从小到大顺序排序

abc
def
==
acd123
44234tjg
aga'-=
ad--s
abd
123
abcdef
123456789012345678901234567890123456789012345678901234567890123
EDFG
SDFG
ABC
DEF
cccc
a*b=1
abc
cccc
dd
def
87&&^
abc
asdfas
234abc35
765rgfh4sd
1231
123
==
EDFG


abc def acd123 44234tjg abd 123 abcdef 123456789012345678901234567890123456789012345678901234567890123 EDFG SDFG ABC DEF cccc dd asdfas 234abc35 765rgfh4sd 1231
== aga'-= ad--s a*b=1 87&&^ ==
bca efd 23acd1 234tjg44 bda 231 efabcd 123456789012345678901234567890123456789012345678901231234567890 FGED FGSD BCA EFD cccc dd asasdf 4abc3523 765rgfh4sd 3112
123456789012345678901234567890123456789012345678901231234567890 231 234tjg44 23acd1 3112 4abc3523 765rgfh4sd BCA EFD FGED FGSD asasdf bca bda cccc dd efabcd efd
'''

import re

all_strings = list()
valid_strings = list()
invalid_strings = list()

while True:
    try:
        s = input().strip()
        if re.match('[0-9a-zA-Z]+$', s):
            if s not in valid_strings:
                valid_strings.append(s)
        else:
            invalid_strings.append(s)
    except EOFError:
        break

new_valid_strings = list()
for s in valid_strings:
    shift = 10 % len(s)
    new_s = s[shift:] + s[:shift]
    new_valid_strings.append(new_s)

print(' '.join(valid_strings))
print(' '.join(invalid_strings))
print(' '.join(new_valid_strings))
print(' '.join(sorted(new_valid_strings)))
