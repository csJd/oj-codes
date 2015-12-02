#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 20;
ll a[N];
char op[N], c;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int k = 0;
        while(scanf(" %lld%c", &a[k], &c))
        {
            op[k++] = c;
            if(c == '\n') break;
        }

        ll m = 1, n = 0, t;
        for(int i = 0; i < k; ++i)
        {
            t = a[i];
            while(op[i] == '+') t += a[++i];
            m *= t;
        }

        for(int i = 0; i < k; ++i)
        {
            t = a[i];
            while(op[i] == '*') t *= a[++i];
            n += t;
        }

        printf("The maximum and minimum are %lld and %lld.\n", m, n);
    }

    return 0;
}
//Last modified :  2015-08-17 15:03 CST

