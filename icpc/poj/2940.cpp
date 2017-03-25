#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int n, k;
    while(scanf("%d", &n), n)
    {
        long long ans = 0, sum = 0;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &k);
            sum += k;
            ans += sum > 0 ? sum : -sum;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
//Last modified :  2015-08-17 19:13 CST

