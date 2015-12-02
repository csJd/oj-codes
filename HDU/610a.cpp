#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e4 + 5;
int main()
{
    int T, n, m, p, q;
    scanf("%d", &T);
    while(T--)
    {
        int ans;
        scanf("%d%d%d%d", &n, &m, &p, &q);
        if(m * p < q) ans = n * p;
        else
        {
            ans = n / m * q;
            n = n % m;
            ans += min(n * p, q);
        }
        printf("%d\n", ans);
    }

    return 0;
}
//Last modified :   2015-07-25 19:01

