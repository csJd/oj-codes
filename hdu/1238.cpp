#include <bits/stdc++.h>
using namespace std;
const int N = 105;
char s[N][N], p1[N], p2[N];
int n, T, len;

bool ok(int i, int j)
{
    int l = j - i;
    for(int k = i; k < j; ++k)
        p1[k - i] = p2[j - 1 - k] = s[0][k];
    p1[l] = p2[l] = 0;
    for(int i = 1; i < n; ++i)
        if(!strstr(s[i], p1) && !strstr(s[i], p2))
            return false;
    return true;
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%s", s[i]);
        len = strlen(s[0]);

        int ans = 0;
        for(int i = 0; i < len; ++i)
            for(int j = len; j > i; --j)
                if(ok(i, j) && j - i > ans) ans = j - i;

        printf("%d\n", ans);
    }
    return 0;
}
//Last modified :  2015-10-04 16:48 CST


