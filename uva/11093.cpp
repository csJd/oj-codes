#include <bits/stdc++.h>
#define cur (i+j)%n
using namespace std;
const int N = 100005;
int p[N], q[N];

int main()
{
    int cas, i, n;
    scanf("%d", &cas);
    for(int k = 1; k <= cas; ++k)
    {

        scanf("%d", &n);
        for(i = 0; i < n; ++i) scanf("%d", &p[i]);
        for(i = 0; i < n; ++i) scanf("%d", &q[i]);
        for(i = 0; i < n; ++i)
        {
            int o = p[i], j = 0;
            while(j < n && o >= q[cur])
                o -= q[cur], ++j, o += p[cur];
            if(j >= n) break;
        }
        printf("Case %d: ", k);
        if(i < n) printf("Possible from station %d\n", i + 1);
        else printf("Not possible\n");
    }
    return 0;
}
