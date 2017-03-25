#include<cstdio>
#include<cstring>
using namespace std;
const int N = 50000, M = 1005;
int p[N], v[N], s[M], cnt, num;
char nam[M][100];

void init_prime()
{
    for(int i = 2; i * i < N; ++i)
        if(!v[i]) for(int j = i; i * j < N; ++j) v[i * j] = 1;
    cnt = 0;
    for(int j = 2; j < N; ++j)
        if(!v[j]) p[++cnt] = j;
}

int main()
{
    int n, cas, ans;
    init_prime();
    scanf("%d", &cas);
    while(cas--)
    {
        ans = 1;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
        {
            s[i] = 0;
            scanf("%s%d", nam[i], &num);
            for(int j = 1; p[j] <= num && j < N; ++j)
            {
                if(num % p[j] == 0) ++s[i];
                while(num % p[j] == 0) num /= p[j];
            }
            if(num != 1) ++s[i];
            if(s[i] > s[ans] || (s[i] == s[ans] && strcmp(nam[i], nam[ans]) < 0))
                ans = i;
        }
        printf("%s\n", nam[ans]);
    }
    return 0;
}
