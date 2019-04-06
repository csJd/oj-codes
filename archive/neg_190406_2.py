"""
3
5
55
5555

5
1N
5HB
"""

b32 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"


def tobi(x):
    ret = ['0' for i in range(10)]
    for i in range(10):
        if (x >> i) & 1 > 0:
            ret[i] = '1'
    ret = ''.join(ret[::-1])
    return ret


def to32(bis):
    bis = bis[::-1]
    ret = 0
    for i in range(5):
        if bis[i] == '1':
            ret += (1 << i)
    return b32[ret]


T = int(input())
for i in range(T):
    dec_str = input().strip()
    n_group, mod = divmod(len(dec_str), 3)
    if mod > 0:
        n_group += 1
        pad = 3 - mod
        dec_str = "0" * pad + dec_str

    arr = [int(dec_str[3*i:3*(i+1)]) for i in range(n_group)][::-1]
    bi_str = ''.join([tobi(x) for x in arr[::-1]]).lstrip('0')
    n_group, mod = divmod(len(bi_str), 5)
    if mod > 0:
        n_group += 1
        pad = 5 - mod
        bi_str = '0' * pad + bi_str
    res = ''.join([to32(bi_str[5*i:5*(i+1)]) for i in range(n_group)])
    print(res)
