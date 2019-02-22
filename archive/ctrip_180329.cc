#include <cstdio>
#include <cstring>
#include <cfloat>
using namespace std;

const int MAX_N = 10086;

int adult[MAX_N], child[MAX_N];
double price[MAX_N];
int num[MAX_N], cur[MAX_N];
double res = DBL_MAX;
int n;

void dfs(int ad, int ch, double pri)
{
    if(ad <= 0 && ch <= 0)
    {
        if(pri < res)
        {
            res = pri;
            memcpy(num, cur, sizeof(cur));
        }
        return;
    }
    for(int i = 0; i < n; ++i)
    {
        cur[i] += 1;
        dfs(ad - adult[i], ch - child[i], pri + price[i]);
        cur[i] -= 1;
    }
}

int main()
{
    int ad, ch, day;

    while(~scanf("%d", &n))
    {
        memset(cur, 0, sizeof(cur));
        int tad = 0, tch = 0;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d%d%lf", &adult[i], &child[i], &price[i]);
            tad += adult[i];
            tch += child[i];
        }
        scanf("%d%d%d", &ad, &ch, &day);

        if(tad && tch)
        {
            dfs(ad, ch, 0);
            if(res < DBL_MAX)
            {
                for(int i = 0; i < n; ++i)
                {
                    printf("%d ", num[i]);
                }
                printf("%.1lf\n", res * day);
            }
        }
        else
        {
            puts("-1");
        }
    }

    return 0;
}

/*
2
2 2 100
4 3 180
3 2 1

2
2 0 100
4 0 180
3 2 1
*/

/*
0 1 180.0
-1
*/
