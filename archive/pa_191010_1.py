astr, bstr = input().split()
a = float(astr)
b = int(bstr)


def pow(x, n):
    ret = 1
    for i in range(n):
        ret *= x
    return ret


eps = 1e-7
le = 0
ri = a
mid = 1
while le + eps < ri:
    mid = (le + ri) / 2
    if pow(mid, b) > a:
        ri = mid
    else:
        le = mid

ans = mid

print(format(ans, ".6f"))
