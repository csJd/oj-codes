#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 100
struct NODE
{
    int top, right, buttom, left;
    bool operator== (const NODE &tmp)
    {
        return top == tmp.top && right == tmp.right && buttom == tmp.buttom && left == tmp.left;
    }
} node[MAX];

int map[MAX][MAX], visit[MAX];
int sum[MAX];
bool ans;
void dfs(int p, const int &n)
{
    if(p == n * n || ans )
    {
        ans = true;
        return;
    }
    int x = p / n, y = p % n;
    for(int i = 0; i < n * n && !ans; ++i)
        if(sum[i])
        {
            if(x > 0)
                if(node[i].top != node[map[x - 1][y]].buttom)
                    continue;
            if(y > 0)
                if(node[i].left != node[map[x][y - 1]].right)
                    continue;
            map[x][y] = i;
            --sum[i];
            dfs(p + 1, n);
            ++sum[i];
        }
}

int main()
{
    int n, ncases = 1;;
    while(scanf("%d", &n) && n)
    {
        if(ncases > 1)
            printf("\n");
        memset(sum, 0, sizeof(sum));
        for(int i = 0; i < n * n; ++i)
        {
            scanf("%d%d%d%d", &node[i].top, &node[i].left, &node[i].buttom, &node[i].right);
            bool flag = false;
            for(int j = 0; j < i; ++j)
                if(sum[j] && node[j] == node[i])
                {
                    ++sum[j];
                    flag = true;
                    break;
                }
            if(!flag)
                ++sum[i];
        }
        memset(map, 0, sizeof(map));
        ans = false;
        dfs(0, n);
        printf("Game %d: ", ncases++);
        if(ans)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }

    return 0;
}



//# include <cstdio>
//# include <cstring>
//
//# define N 25 + 2
//
//bool finished;
//int n, m, t[N][4], num[N], ans[N];
//
//void dfs(int cnt)
//{
//    if (cnt == n*n) {finished = true; return ;}
//    int x = cnt/n + 1, y = cnt%n + 1;
//    int left = cnt, top = cnt+1-n;
//    for (int i = 0; i < m; ++i) if (num[i])
//    {
//        bool ok = true;
//        if (x!=1 && t[i][0] != t[ans[top]][2]) ok = false;
//        if(ok && y!=1 && t[i][3] != t[ans[left]][1]) ok = false;
//        if (ok)
//        {
//            --num[i];
//            ans[cnt+1] = i;
//            dfs(cnt+1);
//            if(finished) return ;
//            ++num[i];
//        }
//    }
//}
//
//void init(void)
//{
//    bool rpt;
//    int top, rig, bot, lef;
//
//    m = 0;
//    memset(num, 0, sizeof(num));
//    for (int i = 0; i < n*n; ++i)
//    {
//        rpt = false;
//        scanf("%d%d%d%d", &top, &rig, &bot, &lef);
//        for (int j = 0; j < m; ++j)
//        {
//            if (t[j][0] == top && t[j][1] == rig &&
//                t[j][2] == bot && t[j][3] == lef)
//                {
//                    rpt = true;
//                    ++num[j];
//                    break;
//                }
//        }
//        if (rpt) continue;
//        t[m][0] = top, t[m][1] = rig, t[m][2] = bot, t[m][3] = lef;
//        ++num[m];
//        ++m;
//    }
//}
//
//void solve(void)
//{
//    finished = false;
//    dfs(0);
//    if (finished) puts("Possible");
//    else puts("Impossible");
//}
//
//int main()
//{
//    int i = 0;
//
//    while (~scanf("%d", &n))
//    {
//        if (!n) break;
//        init();
//        if(i != 0) putchar('\n');
//        printf("Game %d: ", ++i);
//        solve();
//    }
//
//    return 0;
//}
