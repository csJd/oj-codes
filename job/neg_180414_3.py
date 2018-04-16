#!/usr/bin/python
# -*- coding: utf-8 -*-

# markov

import math
init = map(float, raw_input().strip().split())
trans = []
score = []
for i in range(4):
    tmp = map(float, raw_input().strip().split())
    trans.append(tmp)
for i in range(4):
    tmp = map(float, raw_input().strip().split())
    score.append(tmp)
string = raw_input().strip().split()
s = string[0]
a = []
d = {
    'S': 0,
    'A': 1,
    'B': 2,
    'C': 3,
    'D': 4,
    }

for i in range(4):
    t = init[i] * score[i][d[s]]
    a.append(t)
for (i, s) in enumerate(string[1:]):
    newa = []
    for j in range(4):
        tmp = 0
        for k in range(4):
            tmp += a[k] * trans[k][j]
        tmp *= score[j][d[s]]
        newa.append(tmp)
    a = newa
print '%.4f' % math.log10(sum(a))
