#include<cstdio>
int main()
{
    char s1[1005], s2[1005];
    int cas, ans;
    scanf("%d", &cas);
    while(cas--)
    {
        ans = 0;
        scanf("%s%s", s1, s2);
        for(int i = 0; s1[i]; ++i) ans += s1[i] - '0';
        for(int i = 0; s2[i]; ++i) ans += s2[i] - '0';
        printf("%d\n", ans);
    }
    return 0;
}
