#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
int a[N];

int  main()
{
    int m, n, t;
    while(~scanf("%d", &m))
    {
        n = 0;
        while(m--)
        {
            scanf("%d", &t);
            int i = lower_bound(a, a + n, t) - a;
            if(i == n) n++;
            a[i] = t;
        }
        printf("%d\n", t);
    }
    return 0;
}
