#include <bits/stdc++.h>
using namespace std;
const int N = 150005;

struct open
{
    int t, p;
    bool operator< (const open &o) const
    {
        return t < o.t;
    }
} op[N];

struct data
{
    int val, num;
    bool operator< (const data &d) const
    {
        if(val == d.val) return num > d.num;
        return val < d.val;
    }
} tmp;
priority_queue<data> pq;

string nam[N];
int v[N], ans[N];

int main()
{
    int T, n, m, q;
    char s[205];
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &q);
        for(int i = 1; i <= n; ++i)
        {
            scanf("%s%d", s, &v[i]);
            nam[i] = s;
        }


        for(int i = 0; i < m; ++i)
            scanf("%d%d", &op[i].t, &op[i].p);
        sort(op, op + m);

        int t, p, cur = 1;
        n = 1;
        for(int i = 0; i < m; ++i)
        {
            t = op[i].t, p = op[i].p;
            while(cur <= t)
            {
                tmp.val = v[cur];
                tmp.num = cur;
                pq.push(tmp);
                ++cur;
            }

            int cnt = 0;
            while(!pq.empty() && cnt < p)
            {
                ans[n++] = pq.top().num;
                pq.pop();
                ++cnt;
            }
        }

        for(; cur <= n; ++cur)
        {
            tmp.val = v[cur];
            tmp.num = cur;
            pq.push(tmp);
        }

        while(!pq.empty())
        {
            ans[n++] = pq.top().num;
            pq.pop();
        }

        for(int i = 0; i < q; ++i)
        {
            scanf("%d", &n);
            cout << nam[ans[n]] << (i < q - 1 ? " " : "\n");
        }

    }
    return 0;
}
//Last modified :  2015-09-13 13:01 CST
