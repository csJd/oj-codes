#include <bits/stdc++.h>
using namespace std;
const int N = 3000005;
char s[N];

int main()
{
    int T, cas = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", s);
        int l = strlen(s), ans, cnt = 0;
        int oth = 0;
        for(int i = 0; i < l; ++i)
        {
            if(s[i] != 'c' && s[i] != 'f') oth = 1;
            if(s[i] == 'c') ++cnt;
        }

        if(oth) ans = -1;
        else if(cnt == 0) ans = (l + 1) / 2;
        else if(cnt == 1) ans = l > 2 ? 1 : -1;
        else
        {
            ans = cnt;
            int last = -3;
            for(int i = 0; i < l; ++i)  s[l + i] = s[i];
            for(int i = 0; i < l * 2 && ans != -1; ++i)
            {
                if(s[i] != 'c')
                {
                    if(s[i] != 'f') ans = -1;
                    continue;
                }
                if(i - last < 3) ans = -1;
                last = i;
            }
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}
//Last modified :  2015-09-19 12:07 CST

