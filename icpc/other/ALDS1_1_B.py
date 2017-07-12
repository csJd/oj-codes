def gcd(m, n):
    return m if n == 0 else gcd(n, m%n)

a, b = map(int, input().split())
print(gcd(a, b))
