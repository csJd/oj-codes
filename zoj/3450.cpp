#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 505;
int vis[N], dp[10086];

struct enemy
{
    ll x, y;
    int t, w;
} e[N];


bool cmp(enemy a, enemy b)  //����ԭ��ľ�������
{
    return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
}

bool aLine(int i, int j) //�ж��Ƿ���ͬһ�������ϡ�
{
    if(e[i].x * e[j].y == e[i].y * e[j].x)
        return e[i].x * e[j].x >= 0 &&  e[i].y * e[j].y >= 0;
    return 0;
}

int main()
{
    ll x, y, x0, y0;
    int n, t0;
    while(~scanf("%lld%lld%d%d", &x0, &y0, &n, &t0))
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%lld%lld%d%d", &x, &y, &e[i].t, &e[i].w);
            e[i].x = x - x0;
            e[i].y = y - y0;
        }
        sort(e, e + n, cmp);  //����ԭ��ľ�������

        vector<enemy> em[N];  //����һ�������ϵķŵ�һ��������
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; ++i)
        {
            if(vis[i]) continue;  //i�Ѿ��ڱ��������
            em[i].push_back(e[i]);
            for(int j = i + 1; j < n; ++j)
            {
                if(!aLine(i, j)) continue;
                int k = em[i].size() - 1;
                vis[j] = 1;
                if(e[j].t == 0)  //�Ѻ�ʱΪ0�ĵ��˷ŵ���һ����
                {
                    em[i][k].w += e[j].w;
                    continue;
                }

                em[i].push_back(e[j]);
                em[i][k + 1].w += em[i][k].w;
                em[i][k + 1].t += em[i][k].t;
            }
        }

        memset(dp, 0, sizeof(dp)); //���鱳��
        for(int i = 0; i < n; ++i)
        {
            int k = em[i].size();
            for(int v = t0; v >= 0; --v)
                for(int j = 0; j < k && em[i][j].t <= v; ++j)
                    dp[v] = max(dp[v], dp[v - em[i][j].t] + em[i][j].w);
        }
        printf("%d\n", dp[t0]);
    }

    return 0;
}
//Last modified :   2015-07-28 18:43
/*
0 0 5 10
0 5 2 3
0 10 2 8
3 2 4 6
6 7 3 9
4 4 10 2

0 0 5 0
0 5 0 1
0 10 0 1
3 2 0 1
6 7 0 1
4 4 0 1
*/
