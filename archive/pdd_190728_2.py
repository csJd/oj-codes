"""
给定一个字符串数组（字符串长度和数组的长度均大于 1 且小于
1024），所有字符均为大写字母。请问，给定的字符串数组是
否能通过更换数组中元素的顺序，从而首尾相连，形成一个
环，环上相邻字符串首尾衔接的字符相同。

输入描述：
一行输入，空格分隔，表示字符串数组。

输出描述：
一行输出，true 或者 false，表示是否可以形成环

CAT TIGER RPC
true

CAT RPC
false

95%
time consuming
"""


def dfs(arr, res, vis, flag):
    """ dfs
    """

    if flag:
        return True
    if len(arr) == len(res):
        if arr[res[-1]][-1] == arr[res[0]][0]:
            flag = True
        return flag

    for i, word in enumerate(arr):
        if not vis[i] and ((not res) or arr[res[-1]][-1] == word[0]):
            vis[i] = True
            flag = dfs(arr, res + [i], vis, flag)
            vis[i] = False

    return flag


def main():
    """ main """

    arr = input().split()
    length = len(arr)
    if length < 2:
        return False

    vis = [False] * length
    flag = dfs(arr, [], vis, False)
    print("true" if flag else "false")


if __name__ == "__main__":
    main()
