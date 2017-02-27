#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int N = 2016;
ll num[N], a, b;
int main()
{
    int n = 0;
    for(int l = 2; l < 62; ++l)
    {
        ll bas = (1LL << l) - 1;
        for(int j = 0; j < l - 1;  ++j)
        {
            num[n++] = bas - (1LL << j);
            //printf("%lld\n", num[n - 1]);
        }
    }
    //printf("%d\n",  n);
    sort(num, num + n);

    while(~scanf("%lld%lld", &a, &b))
        printf("%d\n", upper_bound(num, num + n, b) - lower_bound(num, num + n, a));
    return 0;
}
//Last modified :  2015-12-30 23:19 CST

