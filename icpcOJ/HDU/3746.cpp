#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
char p[N];
int nex[N];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", p);
        int l = strlen(p);
        int i = 0, j = nex[0] = -1;
        while(i < l)
        {
            if(j == -1 || p[i] == p[j])
                nex[++i] = ++j;
            else j = nex[j];
        }
        int loop = l - nex[l];
        int ans = loop - (l % loop);
        if(l % loop == 0 && l / loop > 1) ans = 0;
        printf("%d\n", ans);
    }
    return 0;
}
//Last modified :  2015-09-22 21:50 CST

