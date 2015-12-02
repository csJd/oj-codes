#include <bits/stdc++.h>
using namespace std;
int a[] = {8, 9, 6, 4, 2, 3, 5, 7};

int main()
{
    int T, n;
    scanf("%d", &T);
    char ans[100];
    while(T--)
    {
        int p = 0;
        scanf("%d", &n);
        if(n < 10) ans[p++] = n + '0', n = 1;
        else
        {
            for(int i = 0; i < 8; ++i)
            {
                while(n % a[i] == 0)
                {
                    ans[p++] = '0' + a[i];
                    n /= a[i];
                }
            }
        }
        ans[p] = 0;
        sort(ans, ans+p);
        if(n > 1) puts("-1");
        else puts(ans);
    }
    return 0;
}
//Last modified :  2015-08-17 16:40 CST

