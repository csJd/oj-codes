MOD = int(1e9+7)

n = int(input())
arr = list(map(int, input().split()))
presum = [0] * n
presum[0] = arr[0]
for i in range(1, n):
    presum[i] = arr[i] + presum[i-1]

m = int(input())
ans = 0
for i in range(m):
    a, b = map(int, input().split())
    ans += presum[b] - (presum[a-1] if a > 0 else 0)

print(ans % MOD)
