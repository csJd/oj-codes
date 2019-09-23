"""
7
1 2 2 1 3 4 3
>> 4
"""
n = int(input())
arr = map(int, input().split())

ans = 0
for x in arr:
    ans ^= x

print(ans)
