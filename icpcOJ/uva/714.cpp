#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;
int a[N], d[N], m, k, maxi;
ll s[N], le, ri, mid, mins, t;

int divs()
{
    int last = 0, cnt = 1;
    for(int i = 1; i <= m; ++i)
    {
        if(s[i] - s[last] > mid)
            last = i - 1, ++cnt;
    }
    return cnt;
}

int main()
{
    int cas;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d %d", &m, &k);
        for(int i = maxi = 1; i <= m; ++i)
        {
            scanf("%d", &a[i]);
            s[i] = s[i - 1] + a[i];
            if(a[i] > a[maxi]) maxi = i;
        }

        le = a[maxi], ri = s[m];
        while(le <= ri)
        {
            mid = (le + ri) >> 1;
            if(divs() <= k) mins = mid, ri = mid - 1;
            else le = mid + 1;
        }

        t = 0;
        memset(d, 0, sizeof(d));
        for(int i = m; i > 0; --i)
        {
            if(t + a[i] > mins)
                d[i] = k--, t = 0;
            if(k >= i) while(i > 0) d[--i] = 1;
            t = t + a[i];
        }

        for(int i = 1; i <= m; ++i)
        {
            printf("%d%c", a[i], i < m ? ' ' : '\n');
            if(d[i]) printf("/ ");
        }
    }
    return 0;
}

/*
100
9 1
100 200 300 400 500 600 700 800 900
9 2
100 200 300 400 500 600 700 800 900
9 3
100 200 300 400 500 600 700 800 900
9 4
100 200 300 400 500 600 700 800 900
9 5
100 200 300 400 500 600 700 800 900
9 6
100 200 300 400 500 600 700 800 900
9 7
100 200 300 400 500 600 700 800 900
9 8
100 200 300 400 500 600 700 800 900
9 1
100 200 300 400 500 600 700 800 900
9 9
100 200 300 400 500 600 700 800 900
*/
