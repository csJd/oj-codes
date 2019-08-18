"""
将长N*M厘米的矩形区域划分成N行M列（每行每列的宽度均为1厘米），在第i行第j列的位置上叠放Ai,j个边长为1厘米的正方体（1≤Ai,j≤100），所有正方体就组成了一个立体图形，每个正方体六个面中的一部分会被其它正方体遮挡，未被遮挡的部分的总面积即为该立体图形的表面积，那么该立体图形的表面积是多少平方厘米？

输入
第一行包含两个整数N和M，1≤N，M≤1000。

接下来N行，每行包含M个整数，第i行的第j个整数表示Ai,j。

输出
输出表面积的大小。


样例输入
2 2
2 1
1 1
样例输出
20

3 3
3 1 3
1 1 1
1 1 1

46
"""


def main():
    n, m = map(int, input().split())
    ans = 0
    mat = []
    for i in range(n):
        mat.append(list(map(int, input().split())))

    for i in range(n):
        for j in range(m):
            ans += 2 + 4 * mat[i][j]
            if i > 0:
                ans -= 2 * min(mat[i][j], mat[i-1][j])
            if j > 0:
                ans -= 2 * min(mat[i][j], mat[i][j-1])
    print(ans)

    # front = 0
    # left = 0
    # up = n * m

    # for i in range(n):
    #     row_max = 0
    #     for j in range(m):
    #         if mat[i][j] > row_max:
    #             row_max = mat[i][j]
    #         if j > 1 and mat[i][j] > mat[i][j-1] and mat[i][j-2] > mat[i][j-1]:
    #             ans += 2 * (min(mat[i][j], mat[i][j-2]) - mat[i][j-1])
    #     left += row_max

    # for j in range(m):
    #     col_max = 0
    #     for i in range(n):
    #         if mat[i][j] > col_max:
    #             col_max = mat[i][j]
    #         if i > 1 and mat[i][j] > mat[i-1][j] and mat[i-2][j] > mat[i-1][j]:
    #             ans += 2 * (min(mat[i][j], mat[i-2][j]) - mat[i][j-1])
    #     front += col_max

    # ans += (up+left+front) * 2
    # print(ans)


if __name__ == "__main__":
    main()
