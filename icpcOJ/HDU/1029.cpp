#include <cstdio>
using namespace std;

int main()
{
    int n, a, t, ans;
    while(~scanf("%d %d", &n, &ans))
    {
        t = 1;
        while(--n)
        {
            scanf("%d", &a);
            if(t == 0) ans = a;
            if(a == ans) ++t;
            else --t;
        }
        printf("%d\n", ans);
    }
    return 0;
}
//Last modified :  2015-08-26 08:05 CST

