#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;

int main()
{
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        priority_queue<int, vector<int>, greater<int> > pq;
        ll ans = 0, a;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
        {
            scanf("%lld", &a);
            pq.push(a);
            if(!i && n > 1) ans += a * (n - 1);
            else ans += a * (n - i);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
