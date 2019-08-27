"""
https://www.nowcoder.com/discuss/235697

算式转移
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
给出一个仅包含加减乘除四种运算符的算式(不含括号)，如1+2*3/4，在保持运算符顺序不变的情况下，现在你可以进行若干次如下操作：如果交换相邻的两个数，表达式值不变，那么你就可以交换这两个数。

现在你可以进行任意次操作，使得算式的数字序列字典序最小，然后输出结果，数字之间的字典序定义为若a<b则a的字典序小于b。

输入
第一行包含一个整数n，表示算式的长度，即包含n个数字和n-1个运算符。(1≤n≤100000)。

第二行包含一个含有n个非0整数和n-1个运算符的算式，整数与运算符用空格隔开，运算符包括“+，-，*，/”，整数的绝对值不超过1000。

输出
按要求输出字典序最小的表达式，数字与符号之间用空格隔开。


样例输入
6
3 + 2 + 1 + -4 * -5 + 1
样例输出
1 + 2 + 3 + -5 * -4 + 1

4
4 + 3 - 2 * 1

4
4 + 3 * 2 * 1

4
4 + 3 / 2 * 1

4
4 - 3 - 2 - 1
"""


def main():
    n_nums = int(input())
    seq = input().split()
    length = len(seq)

    nums = list()
    ops = ['+']  # save the operator before nums[i]
    for i in range(length):
        if i % 2 == 0:
            nums.append(int(seq[i]))
        else:
            ops.append(seq[i])

    le = ri = 0
    while ri < n_nums:
        # nums[le:ri+1] have the same operator before
        while ri < n_nums and ops[ri] == ops[le]:
            ri += 1
        start, end = le, ri
        if ops[le] in '+-':
            if ri < n_nums and ops[ri] in '*/':
                end = ri - 1
        elif ops[le] == '*':
            if le > 0 and ops[le-1] in '+-':
                start = le - 1
        else:  # ops[le] == '/':
            pass
        nums[start:end] = sorted(nums[start:end])
        le = ri

    output = list()
    for i in range(n_nums - 1):
        output.append(str(nums[i]))
        output.append(ops[i+1])
    output.append(str(nums[n_nums - 1]))
    print(" ".join(output))


if __name__ == "__main__":
    main()
