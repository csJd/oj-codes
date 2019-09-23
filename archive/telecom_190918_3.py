"""
maxsum

[2, 4, -2, 5, -6]
>> 9
"""


def main():
    arr = [int(x.strip()) for x in input().strip('[]').split(',')]
    if not arr:
        print(0)
        return

    maxsum = -(1 << 32)
    cursum = 0

    for x in arr:
        if cursum < 0:
            cursum = x
        else:
            cursum += x
        if cursum > maxsum:
            maxsum = cursum
    print(maxsum)


if __name__ == "__main__":
    main()
