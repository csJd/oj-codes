#include <cstdio>
#include <cstring>
using namespace std;
const int N = 65, M = 15;
int nex[N], n;
char s[N][N], p[N];

bool kmp()
{
    int lp = strlen(p), ls = 60;
    int i = 0, j = nex[0] = -1;
    while(i < lp)
    {
        if(j == -1 || p[i] == p[j])
            nex[++i] = ++j;
        else j = nex[j];
    }

    for(int k = 1; k < n; ++k)
    {
        i = j = 0;
        while(i < ls && j < lp)
        {
            if(j == -1 || s[k][i] == p[j])
                ++i,  ++j;
            else j = nex[j];
        }
        if(j < lp) return false;
    }
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%s", s[i]);
        char ans[N] = "no significant commonalities";
        for(int k = 3; k <= 60; ++k)
        {
            for(int i = 0; i + k <= 60; ++i)
            {
                for(int j = p[k] = 0; j < k; ++j) p[j] = s[0][i + j];
                if(kmp() && (strcmp(p, ans) < 0 || k > strlen(ans)))
                    strcpy(ans, p);
            }
        }
        puts(ans);
    }
    return 0;
}
//Last modified :  2015-09-24 20:30 CST

