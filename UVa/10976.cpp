#include<cstdio>
using namespace std;
const int N = 10005;
int x[N], y[N];
int main()
{
    int k, cnt;
    while(scanf("%d", &k) != EOF)
    {
        cnt = 0;
        for(int i = k + 1; i <= 2 * k; ++i)
            if((k * i) % (i - k) == 0)
                y[++cnt] = i, x[cnt] = (k * i) / (i - k);
        printf("%d\n", cnt);
        for(int i = 1; i <= cnt; ++i)
            printf("1/%d = 1/%d + 1/%d\n", k, x[i], y[i]);
    }
    return 0;
}
