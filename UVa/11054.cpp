#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, t;
    long long ans, last;
    while(~scanf("%d", &n), n)
    {
        ans = last = 0;
        //last记录需要从i-1运输到i的量
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &t);
            ans += abs(last), last += t;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//const int N = 100005;
//int a[N], n;
//long long ans;
//
//void solve(int k)
//{
//    int i = 0;
//    while(a[k])
//    {
//        ++i;
//        if(a[k]*a[k + i] > 0) continue;
//        if((a[k] + a[k + i]) * a[k]  <= 0)
//            ans += i * abs(a[k]), a[k + i] += a[k], a[k] = 0;
//        else ans += i * abs(a[k + i]), a[k] += a[k + i], a[k + i] = 0;
//    }
//}
//
//int main()
//{
//    while(~scanf("%d", &n), n)
//    {
//        ans = 0;
//        for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
//        for(int i = 0; i <= n / 2; ++i) if(a[i]) solve(i);
//        printf("%lld\n", ans);
//    }
//    return 0;
//}
