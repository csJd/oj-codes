'''
根据前序遍历和中序遍历还原二叉树
根据获得的前序遍历和中序遍历结果输出一颗二叉树

输入描述:
第一行为二叉树前序遍历的结果
第二行为二叉树中序遍历的结果

输出描述:
二叉树后续遍历的结果
示例1:
输入:
G D A F E M H Z
A D E F G H M Z
输出:
A E F D H Z M G

示例2
输入:
A B D G H E C K F I J
G D H B E A K C I J F
输出:
G H D E B K J I F C A
'''

# coding=utf-8

result = list()


def solve(pre_order, in_order):
    if len(pre_order) < 1:
        return
    if len(pre_order) == 1:
        result.append(pre_order[0])
        # print(pre_order)
        return
    root = pre_order[0]
    pos = in_order.index(root)
    solve(pre_order[1:pos+1], in_order[0:pos])
    solve(pre_order[pos+1:], in_order[pos+1:])
    result.append(root)


pre_order = input().split()  # 'GDAFEMHZ'
in_order = input().split()  # 'ADEFGHMZ'
solve(pre_order, in_order)
print(' '.join(result))
