"""
3 3
40 24 135
200 239 238
90 34 94
2
0.0 0.6
0.1 0.3

106 176
162 174
"""


import math


def main():
    h, w = map(int, input().split())
    data = []
    for i in range(h):
        data.append(list(map(int, input().split())))

    kernel_size = int(input())
    kernel = []
    for i in range(kernel_size):
        kernel.append(list(map(float, input().split())))

    def conv(r, c):
        res = 0
        for i in range(kernel_size):
            for j in range(kernel_size):
                res += data[r+i][c+j] * kernel[i][j]
        return min(math.floor(res), 255)

    result = []
    for i in range(h-kernel_size+1):
        row = []
        for j in range(w-kernel_size+1):
            row.append(conv(i, j))
        result.append(row)

    for i in range(h-kernel_size+1):
        print(" ".join(map(str, result[i])))


if __name__ == "__main__":
    main()
