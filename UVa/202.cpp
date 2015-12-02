#include<cstdio>
#include<cstring>
using namespace std;
const int N = 3005;
int a[N], v[N];

int main()
{
    int n, m, cnt;
    while(~scanf("%d%d", &n, &m))
    {
        cnt = 0;
        memset(v, 0, sizeof(v));
        printf("%d/%d = %d.", n, m, n / m);
        n = n % m;
        while(!v[n])
        {
            a[++cnt] = (n * 10) / m;
            v[n] = cnt;
            n = n * 10 % m;
        }
        for(int i = 1; i <= cnt && i < 51; ++i)
        {
            if(i == v[n]) printf("(");
            printf("%d", a[i]);
            if(i == 50) printf("...");
        }
        printf(")\n   %d = number of digits in repeating cycle\n\n", cnt - v[n] + 1);
    }
    return 0;
}
