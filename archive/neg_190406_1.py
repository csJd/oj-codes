"""
4
7
7 3 3 4 4 5 6
5
2 3 4 6 A
5
A 2 3 4 5
6
3 4 5 6 7 8

4
0
1
3

"""
value_dic = {"A": 1, "J": 11, "Q": 12, "K": 13}
ans = 0


def dfs(arr, pos, cnt):
    global ans
    if cnt > 4:
        ans += 1
    if pos >= len(arr):
        return
    for ind in range(pos+1, len(arr)):
        if arr[ind] != arr[pos] + 1:
            continue
        dfs(arr, ind, cnt+1)


T = int(input())
for i in range(T):
    ans = 0
    n = int(input())
    arr = input().split()
    for i in range(n):
        if arr[i] in "AJQK":
            arr[i] = value_dic[arr[i]]
        else:
            arr[i] = int(arr[i])
    arr = sorted(arr)
    for i in range(0, len(arr)):
        dfs(arr, i, 1)
    print(ans)
