"""
15 10 5,1,1000#2,3,3000#5,2,15000#10,4,16000
31000
"""

disk, ram, apps = input().split()
d = int(disk)
r = int(ram)
app_list = apps.split('#')
n_apps = len(app_list)
vis = [False] * n_apps

ans = 0


def dfs(dr, rr, cur, pos):
    global ans
    if pos >= n_apps:
        ans = max(ans, cur)
        return
    dc, rc, n_users = map(int, app_list[pos].split(','))
    if dr >= dc and rr >= rc:
        dfs(dr-dc, rr-rc, cur+n_users, pos+1)
    dfs(dr, rr, cur, pos+1)


dfs(d, r, 0, 0)

print(ans)
