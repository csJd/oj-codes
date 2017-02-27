#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char s[N];

int main()
{
    int l1, r1, l2, r2, l;
    while(~scanf("%s", s))
    {
        l1 = r1 = l2 = r2 = 0;
        l = strlen(s);

        for(int i = 0; i < l - 1; ++i)
        {
            if(s[i] == 'A' && s[i + 1] == 'B')
            {
                l1 = i+1;
                break;
            }
        }

        for(int i = 0; i < l - 1; ++i)
        {
            if(s[i] == 'B' && s[i + 1] == 'A')
            {
                l2 = i+1;
                break;
            }
        }


        for(int i = l - 2; i >= 0; --i)
        {
            if(s[i] == 'A' && s[i + 1] == 'B')
            {
                r1 = i+1;
                break;
            }
        }

        for(int i = l - 2; i >= 0; --i)
        {
            if(s[i] == 'B' && s[i + 1] == 'A')
            {
                r2 = i+1;
                break;
            }
        }

        puts((l1 && r2 && (r2 > l1 + 1)) || (l2 && r1 && (r1 > l2 + 1)) ? "YES" : "NO");
    }
    return 0;
}
//Last modified :   2015-06-05 00:39

