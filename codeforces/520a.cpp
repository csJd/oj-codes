#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d = 'a' - 'A', i;
    char s[105];
    while(~scanf("%d", &n))
    {
        scanf("%s",s);
        int cnt[200] = {0};
        for(i = 0; s[i]; ++i)
        {
            if(islower(s[i]))  s[i] -= d;
            ++cnt[s[i]];
        }
        for(i = 'A'; i <= 'Z'; ++i)
            if(!cnt[i]) break;
        if(i <= 'Z') puts("NO");
        else puts("YES");
    }
    return 0;
}
