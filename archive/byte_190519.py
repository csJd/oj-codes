'''
有一个 n 边形 (P0,P1,⋯,Pn), 每一边皆为垂直或者水平的线段,
现给定数值 k, 以P0为起点将 n 边形的周长分成 k 段, 每段的长度相同,
请打印出所有的 k 等分点(T0, T1, ⋯, Tk )的坐标
'''


def find_k_segs(points, k):
    points.append(points[0])
    nums = len(points)
    total_len = 0
    for i in range(1, nums):
        total_len += abs(points[i][1] - points[i-1][1]) + \
            abs(points[i][0] - points[i-1][0])
    segment_len = total_len / k
    print(total_len, segment_len)

    remains = 0
    print(points[0])
    for i in range(1, nums):
        is_vertical = (points[i][0] == points[i-1][0])
        length = abs(points[i][1] - points[i-1][1]) + \
            abs(points[i][0] - points[i-1][0])
        sign = 1 if (points[i][0] > points[i-1][0]
                     or points[i][1] > points[i-1][1]) else -1
        next_seg = list(points[i-1])
        while length >= segment_len - remains:
            length -= segment_len
            if is_vertical:
                next_seg[1] += sign * (segment_len - remains)
            else:
                next_seg[0] += sign * (segment_len - remains)
            print(tuple(next_seg))
            remains = 0
        remains = length


def main():
    points = [(0, 0), (0, 1), (1, 1), (1, 2), (2, 2), (2, 0)]
    k = 3
    find_k_segs(points, k)


if __name__ == "__main__":
    main()
