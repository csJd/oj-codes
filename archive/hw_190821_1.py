"""
0x0A 转义为 0x12 0x34 两个字节， 0x0B 转义为 0xAB 0xCD 两字节，输出转义后的字节序列（第一个字节为长度）

8 1 2 3 4 5 6 A
9 1 2 3 4 5 6 12 34
"""
arr = list(input().split())

cnt = len(arr)
for i in range(1, len(arr)):
    if arr[i] == 'A':
        arr[i] = '12 34'
        cnt += 1
    elif arr[i] == 'B':
        arr[i] = 'AB CD'
        cnt += 1
print("%X" % cnt, " ".join(arr[1:]))
