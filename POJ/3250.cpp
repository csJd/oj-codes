#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 1e5;
int h[N], s[N];

int main()
{
    int n, top;
    while(~scanf("%d", &n))
    {
        for(int i = 1; i <= n; ++i)
            scanf("%d", &h[i]);

        ll ans = top = 0;  //找第一个大于的用递减栈
        for(int i = n; i > 0; --i)
        {
            while(top && h[s[top - 1]] < h[i]) --top;
            ans += (top ? s[top - 1] - i - 1: n - i);
            s[top++] = i;
        }

        printf("%I64d\n", ans);
    }
    return 0;
}
//Last modified :   2015-07-06 14:13
