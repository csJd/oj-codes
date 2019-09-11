seq = input()

cnt = 0
for x in seq:
    if x == '0':
        break
    if x == '(':
        cnt += 1
    else:
        cnt -= 1

print(cnt)
