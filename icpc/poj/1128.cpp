#include <cstdio>
#include <cstring>
using namespace std;
const int N = 50;
char ans[N], g[N][N], tp[N][N];
int x1[N], y1[N], x2[N], y2[N];
//(x1,y1)为对应字母的左上角坐标  (x2,y2)为右下
int in[N], n;

void addTopo(int i, int j, int c)
{
    int t = g[i][j] - 'A';
    if(t != c && !tp[c][t])
    {
        ++in[t];
        tp[c][t] = 1;
    }
}

void build()
{
    memset(tp, 0, sizeof(tp)); //tp[i][j] = 1表示有i < j的关系
    for(int c = n = 0; c < 26; ++c)
    {
        if(in[c] < 0) continue;
        for(int i = x1[c]; i <= x2[c]; ++i)
        {
            addTopo(i, y1[c], c);
            addTopo(i, y2[c], c);
        }
        for(int j = y1[c]; j <= y2[c]; ++j)
        {
            addTopo(x1[c], j, c);
            addTopo(x2[c], j, c);
        }
        ++n;//统计出现了多少个字符
    }
}

void topoSort(int k)
{
    if(k == n)
    {
        ans[k] = 0;
        puts(ans);
        return;
    }

    //从前往后找入度为0的点保证升序
    for(int i = 0; i < 26; ++i)
    {
        if(in[i] == 0)
        {
            ans[k] = i + 'A'; //这一位放i
            in[i] = -1;
            for(int j = 0; j < 26; ++j)
                if(tp[i][j]) --in[j];

            topoSort(k + 1); //找下一位

            in[i] = 0; //回溯
            for(int j = 0; j < 26; ++j)
                if(tp[i][j]) ++in[j];
        }
    }
}

int main()
{
    int h, w, c;
    while(~scanf("%d%d", &h, &w))
    {
        for(int i = 0; i < 26; ++i)
        {
            x1[i] = y1[i] = N;
            x2[i] = y2[i] = 0;
        }

        memset(in, -1, sizeof(in));
        for(int i = 0; i < h; ++i)
        {
            scanf("%s", g[i]);
            for(int j = 0; j < w; ++j)
            {
                if((c = g[i][j] - 'A') < 0) continue; //g[i][j] ='.'
                if(i < x1[c]) x1[c] = i;
                if(i > x2[c]) x2[c] = i;
                if(j < y1[c]) y1[c] = j;
                if(j > y2[c]) y2[c] = j;
                in[c] = 0;  //出现过的字母in初始为0  否则为-1
            }
        }
        build();
        topoSort(0);
    }
    return 0;
}
//Last modified :  2015-08-19 19:42 CST
/*
.CCC....
ECBCBB..
DCBCDB..
DCCC.B..
D.B.ABAA
D.BBBB.A
DDDDAD.A
E...AAAA
EEEEEE..
*/

