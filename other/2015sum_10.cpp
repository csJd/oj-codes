#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 105;
int a[N];
int main()
{
    int T,n,m,k,s;
    scanf("%d",&T);
    while(T--)
    {
        s = 0;
        scanf("%d%d%d",&n,&m,&k);
        for(int i = 0; i<k; ++i)
            scanf("%d",&a[i]), s+=a[i];
        if(s<n-m) puts("-1");
        else
        {
            int cnt = 0;
            s = n - m;
            sort(a,a+k);
            for(int i = k-1; i>=0 && s > 0; --i)
            {
                s -= a[i]; ++cnt;
            }

            printf("%d\n",cnt);
        }

    }
    return 0;
}


