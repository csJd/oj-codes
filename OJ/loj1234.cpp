#include <cstdio>
using namespace std;
const int N = 2e6 + 5, M = 50;
double harm[N];

void initHarm()
{
    for(int i = 1, j = 1; i < 1e8; ++i)
    {
        if(i % M == 0) harm[j + 1] = harm[j++];
        harm[j] += 1.0 / i;
    }
}

int main()
{
    initHarm(); //harm[i] 保存的是h[i*M - 1]
    int T, n, cas = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        int i = n / M, j = i * M ? i * M : 1;
        double ans = harm[i];
        while(j <= n) ans += 1.0 / j++;
        printf("Case %d: %.10f\n", ++cas, ans);
    }

    return 0;
}
//Last modified :  2015-08-07 09:34 CST

