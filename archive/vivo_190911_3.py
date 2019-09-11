"""
LeetCode 546

1 4 2 2 3 3 2 4 1
21

80% AC
"""

inp = input().split()
ans = 0


def dfs(arr, points):
    global ans
    if len(arr) == 0:
        ans = max(points, ans)
        return

    length = len(arr)
    for i in range(length):
        if i > 0 and arr[i] == arr[i-1]:
            continue
        j = i+1
        while j < length and arr[j] == arr[i]:
            j += 1
        dfs(arr[:i]+arr[j:], points+(j-i)*(j-i))


dfs(inp, 0)
print(ans)
