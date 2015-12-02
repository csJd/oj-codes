#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
const int N = 205, M = 20005;
struct line
{
    int x, y;
    bool operator < (const line &l) const
    {
        if(x == l.x) return y < l.y;
        return x < l.x;
    }
} k;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int x[N], y[N];

int main()
{
    int n, d;
    while(~scanf("%d", &n))
    {
        set<line> cnt;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d%d", &x[i], &y[i]);
            for(int j = 0; j < i; ++j)
            {
                d = gcd(x[i] - x[j], y[i] - y[j]);
                k.x = (x[i] - x[j]) / d;
                k.y = (y[i] - y[j]) / d;
                cnt.insert(k);
            }
        }
        printf("%d\n", cnt.size());
    }
    return 0;
}
//Last modified :  2015-08-10 20:01 CST

