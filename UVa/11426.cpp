#include<cstdio>
const int N = 4000005;
typedef long long ll;
int phi[N];
ll g[N];

void init() //O(N*logN) 筛欧拉函数
{
    for(int i = 2; i < N; ++i) phi[i] = i;
    for(int i = 2; i < N; i ++)
    {
        if(phi[i] == i) //i是素数
        {
            for(int j = i; j < N; j += i)
                phi[j] = phi[j] / i * (i - 1);
            //需要从j中删除一个素因子i  因为phi(p^k) = (p-1) * p^(k-1)
        }
        for(int j = 1; j * i < N; j ++)
            g[j * i] += j * phi[i];
        //phi[i]是小于i且与i互质的数的个数 j * i < N 时 j * x 肯定也小于n
        //设x为其中一个数 gcd(x, i) = 1, gcd(2*x, 2*i) = 2 ... ,gcd(j*x, j*i) = j
    }
    for(int i = 1; i < N; i ++) g[i] += g[i - 1];
}

int main()
{
    init();
    int n;
    while(scanf("%d", &n), n)
        printf("%lld\n", g[n]);
    return 0;
}

