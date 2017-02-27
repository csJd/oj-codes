#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
typedef vector<int>::iterator it;
vector<int> tre[N];
priority_queue<int> pq;
int val[N];

void dfs(int r)
{
    pq.push(val[r]);
    for(it i = tre[r].begin(); i != tre[r].end(); ++i)
        dfs(*i);
}

int main()
{
    int n, r, q;
    while(~scanf("%d", &n))
    {
        scanf("%d", &val[0]);
        for(int i = 0; i < n; ++i)
            tre[i].clear();
        for(int i = 1; i < n; ++i)
        {
            scanf("%d%d", &r, &val[i]);
            tre[r].push_back(i);
        }

        scanf("%d", &q);
        while(q--)
        {
            while(!pq.empty()) pq.pop();
            scanf("%d", &r);
            dfs(r);
            if(pq.size() < 3) puts("-1");
            else
            {
                for(int i = 0; i < 2; ++i)
                {
                    printf("%d ", pq.top());
                    pq.pop();
                }
                printf("%d\n", pq.top());
            }
        }
    }
    return 0;
}
//Last modified :   2015-07-14 17:48
