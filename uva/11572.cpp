#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
set<int> have;
int a[N];

int main()
{
    int l, r, n, cas, ans;
    scanf("%d", &cas);
    while(cas--)
    {
        have.clear();
        scanf("%d", &n);
        l = r = ans = 0;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
            while(have.count(a[i])) have.erase(a[l++]);
            have.insert(a[r = i]);
            if(r - l > ans) ans = r - l;
        }
        printf("%d\n", ans + 1);
    }
    return 0;
}
