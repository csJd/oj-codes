#include <bits/stdc++.h>
using namespace std;
char s[200], t[10], ans[10];
int main()
{
    int cas = 0, cur, n, p, k;
    while(scanf("%d", &n), n)
    {
        for(int i = 0; i < n; ++i) scanf("%s", s);
        scanf("%s%d", s, &k);
        p = 0;
        while(k--)
        {
            cur = 0;
            scanf("%s", t);
            for(int j = strlen(t) - 1, i = 1; j >= 0; --j, i <<= 1)
                if(t[j] == '1') cur += i;
            ans[p++] = s[cur];
        }
        ans[p] = 0;
        printf("S-Tree #%d:\n%s\n\n", ++cas, ans);
    }
    return 0;
}
