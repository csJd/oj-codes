#include <cstdio>
using namespace std;
const int N = 1005;
int a[N];

int main()
{
    int T, n, s, t;
    scanf("%d", &T);
    while(T--)
    {
        int cnt = 0;
        scanf("%d%d%d", &n, &s, &t);
        if(s == t && n > 1) puts("-1");
        else
        {

            if(t == s + 1) for(int i = s; i > 0; --i) a[cnt++] = i;
            else
            {
                for(int i = s; i < t; ++i) a[cnt++] = i;
                for(int i = 1; i < s; ++i) a[cnt++] = i;
            }
            for(int i = n; i >= t; --i) a[cnt++] = i;

            for(int i = 0; i < n - 1; ++i)
                printf("%d ", a[i]);
            printf("%d\n", a[n - 1]);
        }
    }
    return 0;
}
//Last modified :  2015-12-05 20:40 CST

