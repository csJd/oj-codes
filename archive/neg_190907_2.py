"""
给定棵二叉树，每个结点有一个正整数权值。若棵叉树，每一层的结点权值和都严格小于下一层的结点权值和，则称这棵二叉
树为递增二叉树。现在给你一棵二叉树，你需要判断其是不是棵递增二 叉树。

输入描述:
输入的第一行是一个正整数工(O < T <= 50)。接下来有T组样例，对于每组样例，输入的第一行是一个正整数N, 表示树
的结点个数(0 < N <= 1000，结点编号为0到N-1)。接下来是N行，第k行表示编号为k的结点，输入格式为: VALUE
LEFT RIGHT,其中VALUE表示其权值，是一个不超过5000的自然数; LEFT和RIGHT分别表示该结点的左子编号和右子编
号。如果其不存在左子或右子，则LEFT或RIGHT为-1。

输出描述:
对于每一组样例，输出一个字符串。如果该二叉树是一棵递增树，则输出 YES，否则输出 NO。

2
8
2 -1 -1
1 5 3
4 -1 6
2 -1 -1
3 0 2
2 4 7
7 -1 -1
2 -1 -1
8
21 6 -1
52 4 -1
80 0 3
31 7 -1
21 -1 -1
59 -1 -1
50 5 -1
48 -1 1
"""

from collections import deque


def main():
    n_cases = int(input())
    while n_cases > 0:
        n_cases -= 1
        n = int(input())
        val = [0] * n
        left = [0] * n
        right = [0] * n

        vis = [0] * n
        for i in range(n):
            val[i], left[i], right[i] = map(int, input().split())
            if left[i] >= 0:
                vis[left[i]] = 1
            if right[i] >= 0:
                vis[right[i]] = 1

        root = 0
        for i in range(n):
            if vis[i] == 0:
                root = i
                break

        q = deque()
        cur_level = 0
        q.append((root, 0))
        last_sum = -1
        level_sum = -1
        while q:
            node, level = q.popleft()
            if level > cur_level:
                if level_sum <= last_sum:
                    print("NO")
                    break
                cur_level = level
                last_sum = level_sum
                level_sum = 0
            level_sum += val[node]
            if left[node] >= 0:
                q.append((left[node], level+1))
            if right[node] >= 0:
                q.append((right[node], level+1))
        else:
            print("YES")


if __name__ == "__main__":
    main()
