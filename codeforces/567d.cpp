#include <bits/stdc++.h>
using namespace std;
set<int> p;
typedef set<int>::iterator it;
pair<set<int>::iterator, bool> pir;
int main()
{
    int n, m, k, a, t, le, ri, cnt;
    scanf("%d%d%d%d", &n, &k, &a, &m);
    int ans = -1;
    a++;
    cnt = (n + 1) / a;
    p.insert(0);
    p.insert(n + 1);
    it ml, mr;
    for(int i = 1; i <= m; ++i)
    {
        scanf("%d", &t);
        if(ans < 0)
        {
            pir =  p.insert(t);
            if(!pir.second) continue;
            ml = mr = pir.first;
            le = *(--ml);
            ri = *(++mr);
            cnt -= (ri - le) / a;
            cnt += (ri - t) / a + (t - le) / a;
            if(cnt < k) ans = i;
        }

    }
    printf("%d\n", ans);

    return 0;
}
//Last modified :   2015-08-06 01:38


