"""
小明的有5个歌单，编号分别为A、B、C、D、E，每个歌单有三首不同的歌，现在他想
要一个程序，当他输入一些歌单的名称的时候，每个歌单中输出一首歌到播放列表，并
输出所有满足条件的播放列表。
输入:输入一个仅包含且不重复的A-E的字符串
输出:输出所有满足条件的播放列表(输出需要有序，字母必须大写)

AC
>> A1C1 A1C2 A1C3 A2C1 A2C2 A2C3 A3C1 A3C2 A3C3
"""
albums = list(input())
n_albums = len(albums)
albums.sort()
ans = list()


def dfs(pos, cur):
    if pos == n_albums:
        ans.append(cur)
        return
    for i in range(1, 4):
        dfs(pos+1, cur+albums[pos]+str(i))


dfs(0, '')
print(' '.join(ans))
