#include <cstdio>
using namespace std;
const int N = 10001;
bool yes[N];

bool isPrime(int n)
{
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0) return false;
    return true;
}

int main()
{
    int a, b;
    for(int i = 0; i < N; ++i)
        yes[i] = isPrime(i * i + i + 41);

    while(~scanf("%d%d", &a, &b))
    {
        int cnt =  0, n;
        for(int i = a; i <= b; ++i)
            cnt += yes[i];
        printf("%.2f\n", cnt * 100.0 / (b - a + 1) + 1e-8);
    }

    return 0;
}
//Last modified :  2015-08-09 20:35 CST

