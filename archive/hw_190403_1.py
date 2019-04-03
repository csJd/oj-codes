'''
4
2,5,6,7,9,5,7
1,7,4,3,4
'''

length = int(input())
arrs = list()
while True:
    try:
        arr = input().strip().split(',')
        arrs.append(arr)
    except EOFError:
        break
ind = 0
over = False
res = list()
while not over:
    over = True
    for arr in arrs:
        if ind < len(arr):
            over = False
        res.extend(arr[ind:ind+length])
    ind += length

print(','.join(res))
