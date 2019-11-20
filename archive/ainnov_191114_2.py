"""
超速检测
时间限制：C/C++语言 1000MS；其他语言 3000MS

题目描述：
问题描述： 高速公路上有一个超速检测仪器，检测通过车辆的车速。根据一段时间通过的车辆车速列表，为列表中的每辆车找到下一辆车速超过它的车辆。输出结果列表时，如果该车通过之后，没有车速超过它的车辆，则其对应位置为-1。 如，给定一个列表speeds=[55, 55, 80]，你的输出应该是[2, 2, -1]； 再比如，给定一个列表speeds=[72, 65, 55, 60, 81, 50, 69]，你的输出应该是[4, 4, 3, 4, -1, 6, -1]。

输入
一行使用空格分隔各个元素的字符串

输出
每个元素的下一个更大元素的index（index从0开始）

样例输入
72 65 55 60 81 50 69
样例输出
4 4 3 4 -1 6 -1
"""


def main():
    arr = [int(x) for x in input().split()]
    length = len(arr)
    gt = dict()
    mst = list()  # mono stack
    for i in range(length):
        while len(mst) > 0 and arr[mst[-1]] < arr[i]:
            gt[mst[-1]] = i
            mst.pop()
        mst.append(i)
    ans = list()
    for i in range(length):
        if i in gt:
            ans.append(gt[i])
        else:
            ans.append(-1)
    print(' '.join(map(str, ans)))


# def bf():
#     arr = [int(x) for x in input().split()]
#     length = len(arr)
#     ans = list()
#     for i, x in enumerate(arr):
#         ind = -1
#         for j in range(i+1, length):
#             if arr[j] > arr[i]:
#                 ind = j
#                 break
#         ans.append(ind)

#     print(' '.join(map(str, ans)))


if __name__ == "__main__":
    main()
