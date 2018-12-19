#include<cstdio>
#include<cstring>
using namespace std;
int n, t;
const int N = 105;
double a[N], b[N], c[N];

int boring(int x)
{
    for(int i = 1; i <= n; ++i)
        if(a[i]*x * x + b[i]*x + c[i] < 0) return false;
    return true;
}

int main()
{
    while(scanf("%d%d", &n, &t), n)
    {
        int  s = 0, e, ans;
        for(int i = 1; i <= n; ++i)
            scanf("%lf %lf %lf", &a[i], &b[i], &c[i]);
        while(s <= t && !boring(s) ) ++s;
        e = s;
        while(e + 1 <= t && boring(e + 1)) ++e;
        ans = e - s;
        if(ans >= t) printf("Cannot Stop\n", ans);
        else if(ans > 0) printf("%d\n", ans);
        else printf("Unhappy\n");
    }
    return 0;
}
