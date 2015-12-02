#include <bits/stdc++.h>
using namespace std;
const int N = 10005, M = 1000005;
char s[M], p[N];
int nex[N];

int kmp()
{
    int ls = strlen(s), lp = strlen(p);
    int i = 0, j = nex[0] = -1;
    while(i < lp)
    {
        if(j == -1 || p[j] == p[i])
            nex[++i] = ++j;
        else j = nex[j];
    }

    int ret = i = j = 0;
    while(i < ls)
    {
        if(j == -1 || s[i] == p[j])
        {
            ++i, ++j;
            if(j == lp) ++ret, j = nex[j];
        }
        else j = nex[j];
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s%s", p, s);
        printf("%d\n", kmp());
    }
    return 0;
}
//Last modified :  2015-09-21 19:20 CST

