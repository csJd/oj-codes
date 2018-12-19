def isPrime(n):
    i = 2
    while i * i <= n:
        if n%i == 0:
            return False
        i += 1
    return True

cnt = 0
n = int(input())

while n:
    a = int(input())
    if isPrime(a):
        cnt += 1
    n -= 1

print(cnt)
