#include <cstdio>
using namespace std;

int main()
{
    int n, t, cnt;
    long long ans;
    while(~scanf("%d", &n))
    {
        ans = cnt = 0;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &t);
            cnt += t;
            if(t == 0) ans += cnt;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
