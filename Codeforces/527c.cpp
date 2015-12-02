#include <bits/stdc++.h>
#define CLR(i) memset(i,0,sizeof(i))
using namespace std;
const int N = 200005;
typedef long long LL;
set<int>::iterator i, j;
set<int> ve, ho;  //记录所有边的位置
int wi[N], hi[N];  //记录存在的边长值
int main()
{
    int w, n, h, p, mw, mh;
    char s[10];
    while(~scanf("%d%d%d", &w, &h, &n))
    {
        CLR(wi), CLR(hi);
        ve.clear(), ho.clear();
        ve.insert(0), ho.insert(0);
        ve.insert(w), ho.insert(h);
        wi[w] = hi[h] = 1;
        mw=w,mh=h;
        while(n--)
        {
            scanf("%s%d", s, &p);
            if(s[0] == 'V')
            {
                ve.insert(p), i = j = ve.find(p);
                --i, ++j, --wi[*j - *i];
                ++wi[p - *i], ++wi[*j - p];
            }
            else
            {
                ho.insert(p), i = j = ho.find(p);
                --i, ++j, --hi[*j - *i];
                ++hi[p - *i], ++hi[*j - p];
            }
        
            while(!wi[mw]) --mw;
            while(!hi[mh]) --mh;
            printf("%lld\n", LL(mw)*LL(mh));
        }
    }
    return 0;
}
