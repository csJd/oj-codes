#include<cstdio>
#include<cstring>
using namespace std;
const int N = 30005;
int a[N], n, t,s;
int main()
{
    while(~scanf("%d %d", &n, &t))
    {
        s = 1;
        for(int i = 1; i < n; ++i)
            scanf("%d", &a[i]);
        while(s < t) s += a[s];
        if(s == t) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
