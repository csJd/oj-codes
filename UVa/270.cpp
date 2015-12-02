#include <bits/stdc++.h>
using namespace std;
const int N = 705;
int x[N], y[N];

bool aLine(int i, int j, int k)
{
    return (x[i] - x[j]) * (y[j] - y[k]) == (x[j] - x[k]) * (y[i] - y[j]);
}

int main()
{
    int T, ans;
    char s[100];
    scanf("%d\n", &T);
    while(T--)
    {
        int n = 0;
        while(gets(s))
        {
            if(!s[0]) break;
            sscanf(s, "%d %d", &x[n], &y[n]);
            ++n;
        }

        ans = n < 3 ? n : 2;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                int cnt = 2;
                for(int k = j + 1; k < n; ++k)
                    if(aLine(i, j, k)) ++cnt;
                if(cnt > ans) ans = cnt;
            }
        }
        printf("%d\n", ans);
        if(T) puts("");
    }
    return 0;
}
//Last modified :  2015-08-17 20:24 CST

