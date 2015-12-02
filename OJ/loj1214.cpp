#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 205;

int main()
{
    int T;
    char a[N];
    ll b, d;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas)
    {
        scanf("%s%lld", a, &b);
        for(int i = d = 0; a[i]; ++i)
        {
            if(a[i] == '-') continue;
            d = (d * 10 + a[i] - '0') % b;
        }
        if(a[0] == '-') d = (-d + b) % b;
        printf("Case %d:%s divisible\n", cas, d ? " not" : "");
    }
    return 0;
}
//Last modified :   2015-07-12 08:13

