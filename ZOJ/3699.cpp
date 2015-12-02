#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
ll l[N], c[N], p[N], r[N], v;
int q[N];

int main()
{
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%lld", &n, &v);
        bool flag = 0;
        for(int i = 0; i < n; ++i)
        {
            scanf("%lld%lld%lld", &l[i], &c[i], &p[i]);
            if(l[i] * c[i] > v) flag = 1;
        }

        if(flag)
        {
            puts("Impossible");
            continue;
        }

        int front = 0, rear = 0, poi;
        ll ans = 0, use, need;
        memset(r, 0, sizeof(r));
        for(int i = 0; i < n; ++i)
        {
            r[i] = front < rear ? l[i - 1] * c[i - 1] : v;  //r[i]表示在i点最多能加多少油
            while(front < rear && p[q[rear - 1]] > p[i])
            {
                --rear;
                r[i] += r[rear];
            }
            q[rear++] = i;                  //取最小值用递增队列

            need = l[i] * c[i];             //need表示这段路需要多少油
            while(need)
            {
                poi = q[front];             //poi表示当前加油最便宜的点
                use = min(r[poi], need);    //use表示这次在能用poi的多少油
                r[poi] -= use;
                need -= use;
                ans += p[poi] * use;
                if(!r[poi]) ++front;
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}
/*
5
5 30
2 3 5
2 5 10
2 5 20
2 5 30
2 5 40

5 30
2 2 1
2 2 1
2 2 1
2 5 10
3 10 3

3 95
10 1 0
90 1 1
10 1 100
*/

//Last modified :   2015-07-08 10:27
