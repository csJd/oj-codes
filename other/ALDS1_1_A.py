n = int(input())
arr = list(map(int, input().split()))
for i in range(0, n):
    key = arr[i]

    j = i - 1
    while j >= 0 and arr[j] > key:
        arr[j+1] = arr[j]
        j -= 1
    arr[j+1] = key

    print(('%d ' * (n - 1) + '%d') % tuple(arr))
