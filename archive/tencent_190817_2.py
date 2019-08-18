"""
题目描述
小Q在玩一个游戏,这是一个 n*m 的面板上面有两种符号一种是'.' 一种是‘X', 其中是还没被破
坏，'X'是已经被破坏，已经被破坏的方块走一-次就会碎掉(不能再走了) ,没被破坏的能走两次才
会碎掉。
现在告诉你起点和终点(面板的左上角坐标为(1, 1),右下角坐标为(n, m))。问你能否走到终点并且
使终点的方块恰好碎掉。

输入描述:
每个测试点有多组测试用例。
输入的第一行为测试用例数  t (1 <= t <= 10)。
接下来包含 t 组测试用例，每一组构成如下:
第一行两个数表示 n,m(1≤n, m≤500)。
第 2~n+1 行表示给定的 n*m 的面板。
第 n+2 行两个数表示起点
第 n+3 行两个数表示终点
输出描述:
对于每个测试用例，如果能输出"YES"不能输出“NO”

2
4 6
X...XX
...XX.
.X..X.
......
1 6
2 2
9 47
....X.X.X.X...X..X.....X..X..X..X....X.X...X..X
XX..X...X.........X...X...X..X.XX......X...X...
..XX...X.......X.....X.....X.XX..X.....X..XX...
.X...XX....X...X.......X.X...X......X.X.X......
X......X..X.XXX....X...X.X.XX..X.......X....X.X
....XX.X...X.XXX.X..XX.XXX...XXX..XX.X.X.XX..XX
.........X...X.XXXX...XX.XX....XX..X...X....X..
.............X....XXXX....X.X...XX.XX.X.X..X...
.X......X.....X......X......X.X.X..X.......XXX.
2 34
7 30

YES
NO
"""

from collections import deque


def main():
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    n_cases = int(input())
    while n_cases > 0:
        n_cases -= 1
        n, m = map(int, input().split())
        board = list()
        for i in range(n):
            board.append(list(input()))
        start_r, start_c = map(int, input().split())
        end_r, end_c = map(int, input().split())

        queue = deque()
        queue.append((start_r-1, start_c-1))
        flag = False
        while queue and (not flag):
            r, c = queue.popleft()
            for d in range(4):
                nr = r + dx[d]
                nc = c + dy[d]
                if 0 <= nr < n and 0 <= nc < m:
                    if board[nr][nc] == 'X' and nr == end_r-1 and nc == end_c-1:
                        flag = True
                        break
                    elif board[nr][nc] == '.':
                        board[nr][nc] = 'X'
                        queue.append((nr, nc))
        print("YES" if flag else "NO")


if __name__ == "__main__":
    main()
