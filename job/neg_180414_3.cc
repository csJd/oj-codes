// brute force

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN = 52;
const int MAXM = 5;

double nexMat[MAXM][MAXM];
double awdMat[MAXM][MAXM];
double start[MAXM];
double ans = 0;
int target[MAXN], len;

void dfs(int step, double cur[], double p)
{
    if(step >= len)
    {
        ans += p;
        return;
    }
    int lev = target[step];
    for(int i = 0; i < 4; ++i)
    {
        dfs(step + 1, nexMat[i], p * awdMat[i][lev] * cur[i]);
    }
}

int main()
{
    for(int i = 0; i < 4; ++i)
    {
        scanf("%lf", &start[i]);
    }

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            scanf("%lf", &nexMat[i][j]);
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            scanf("%lf", &awdMat[i][j]);
        }
    }


    char str[2];
    len = 0;
    while(scanf("%s", str) != EOF)
    {
        // putchar(str[0]);
        int lev = str[0] - 'A' + 1;
        if(lev > 4)
        {
            lev = 0;
        }
        target[len++] = lev;
    }

    double p = 1.0;
    dfs(0, start, p);
    printf("%.4lf\n", log10(ans));

    return 0;
}

/*
0.4 0.3 0.2 0.1
0.5 0.2 0.2 0.1
0.1 0.4 0.1 0.4
0.3 0.1 0.3 0.3
0.2 0.4 0.2 0.2

0.05 0.10 0.20 0.30 0.35
0.08 0.15 0.25 0.35 0.17
0.15 0.25 0.30 0.20 0.10
0.20 0.40 0.20 0.15 0.05

D B B A
*/
