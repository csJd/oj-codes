#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, d, a, ans;
    while(~scanf("%d", &n), n != -1)
    {
        while(n--)
        {
            ans = 1;
            scanf("%d%d", &d, &a);
            while(--d)
            {
                if(a % 2) ans *= 2;
                else ans = ans * 2 + 1;
                a = (a + 1) / 2;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
