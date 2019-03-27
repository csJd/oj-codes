"""
小明在玩切水果游戏，已知屏幕上有若干水果，只允许用直线切水果，一次只允许划出一条直线，直线上的水果都会被消除掉
请求出小明最少需要切多少次才能把屏幕上的水果都切掉。已知屏幕由40 X 50的小方格组成，经过每个方格划出的直线最多只有四条，如下图所示经过红色方格能划出的直线最多只有四条，其中相同数字的方格属于同一条直线屏幕左上角坐标为(0, 0)，右下角坐标为(39, 49)。

第一行输入整数N(0<N<36),接下来N行，每行两个整数 X, Y(0<X<40,0<Y<50)用空格隔开，表示水果所在方格的x坐标和y坐标，不同水果的坐标一定不同; 输入保证合法。

输出描述:
程序输出一一个整数并换行，表示小明需要切水果的最少次数。
"""

n = int(input())
vis = [[0 for i in range(50)] for j in range(50)]
for i in range(n):
    r, c = map(int, input().split())
    vis[r][c] = 1

cnt = 0
while n:
    line_type, line, maxv = 0, 0, 0
    for r in range(40):
        if sum(vis[r]) > maxv:
            maxv = sum(vis[r])
            line = r
            line_type = 0

    for c in range(50):
        colv = 0
        for r in range(40):
            colv += vis[r][c]
        if colv > maxv:
            maxv = colv
            line = c
            line_type = 1

    for m in range(-49, 50):
        mv = 0
        for r in range(40):
            c = r - m
            if 50 > c >= 0:
                mv += vis[r][c]
        if mv > maxv:
            maxv = mv
            line_type = 2
            line = m

    for d in range(0, 99):
        dv = 0
        for r in range(40):
            c = d - r
            if 50 > c >= 0:
                dv += vis[r][c]
        if dv > maxv:
            maxv = dv
            line = d
            line_type = 3

    n -= maxv
    if line_type == 0:
        for c in range(50):
            vis[line][c] = 0
    elif line_type == 1:
        for r in range(40):
            vis[r][line] = 0
    elif line_type == 2:
        for r in range(40):
            c = r - line
            if 50 > c >= 0:
                vis[r][c] = 0
    elif line_type == 3:
        for r in range(40):
            c = line - r
            if 50 > c >= 0:
                vis[r][c] = 0
    cnt += 1
print(cnt)
