#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
ll h[N], s[N], le[N], ri[N];

int main()
{
    int n, top;
    while(scanf("%d", &n), n)
    {
        for(int i = 1; i <= n; ++i)
            scanf("%I64d", &h[i]);

        top = 0, s[0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            while(top && h[s[top]] >= h[i]) --top;
            le[i] = s[top];
            s[++top] = i;
        }

        top = 0, s[0] = n + 1;
        for(int i = n; i > 0; --i)
        {
            while(top && h[s[top]] >= h[i]) --top;
            ri[i] = s[top] - 1;
            s[++top] = i;
        }

        ll ans = h[1];
        for(int i = 1; i <= n; ++i)
            if(h[i] * (ri[i] - le[i]) > ans)
                ans =  h[i] * (ri[i] - le[i]);
        printf("%I64d\n", ans);
    }
    return 0;
}
