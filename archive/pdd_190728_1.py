"""
给定两个数组 A 和 B。其中数组 2 是几乎严格升序排列的，几乎
的定义是只需改变其中 1 个数,即可满足完全升序排列。
你的任务是从数组 A 中找到这个数字，并从数组 B 中选取一个数
将其替换，使得数组 A 是完全严格升序排列的。(严格升序排
列，即不允许相邻两个为相同的数)
请找出数组 B 中满足要求的最大数字，并输出最终有序的数组。
如果不存在就输出 NO。

输入描述：
共两行，第一行是数组 A,第二行是数组 B,元素之间用空格分隔
(数组 A 的长度，数组 B 的长度 < 100)

输出描述：
共一行，为最终有序的数组，不存在则输出 NO。


1 3 7 4 10
2 1 5 8 9

1 3 7 9 10


20 1 23
50 26 7

NO

submission %85
hack case:
1 3 3 4 5
2
"""


def main():
    """ main """
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    la = len(a)
    lb = len(b)

    pos = 0
    for i in range(1, la):
        if a[i] <= a[i-1]:
            pos = i

    flag = False
    maxv = 0
    for val in b:
        if (pos == 0 or val > a[pos - 1]) and \
            (pos == la-1 or val < a[pos + 1]) and \
                ((not flag) or val > maxv):
            a[pos] = maxv = val
            flag = True

    if flag:
        print(' '.join(map(str, a)))
    else:
        print("NO")


if __name__ == "__main__":
    main()
