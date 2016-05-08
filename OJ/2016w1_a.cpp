#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100;
int a[N], b[N];

int main()
{
    for(int i = 0; i < N; ++i)
        a[i] = i * i * i, b[i] = i * (i + 1) * (i + 2) / 6;

    int n, ans;
    while(~scanf("%d", &n), n)
    {
        int ans = 0;
        for(int i = 0; i < 55; ++i)
            for(int j = 0; a[i] + b[j] <= n; ++j)
                if(a[i] + b[j] > ans) ans = a[i] + b[j];
        printf("%d\n", ans);
    }
    return 0;
}
