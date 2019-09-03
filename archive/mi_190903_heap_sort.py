"""
Heap Sort
"""


def fix_up(arr, k):
    while k:
        p = (k-1) // 2  # parent of k
        if arr[p] < arr[k]:
            arr[p], arr[k] = arr[k], arr[p]
            k = p
        else:
            break


def fix_down(arr, length):
    p = 0
    while p * 2 + 1 < length:
        c = p * 2 + 1  # left child
        if c + 1 < length and arr[c+1] > arr[c]:
            c += 1  # right child
        if arr[p] < arr[c]:
            arr[p], arr[c] = arr[c], arr[p]
        else:
            break


def heap_sort(arr):
    length = len(arr)
    if length == 0:
        return arr

    # make arr a heap
    for k in range(1, length):
        fix_up(arr, k)

    # heap sort
    pos = length - 1
    while pos:
        arr[pos], arr[0] = arr[0], arr[pos]
        fix_down(arr, pos)
        pos -= 1
    return arr


def main():
    print(heap_sort([5, 3, 1, 4, 2, 7, 6]))
    print(heap_sort([]))
    print(heap_sort([1, 1, 1]))


if __name__ == "__main__":
    main()
