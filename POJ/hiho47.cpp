#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

vector<int> e[N];
vector<int>::iterator it;
int n, m, ideg[N];

bool topo()
{
    int cur;
    queue<int> q;
    for(int i = 1; i <= n; ++i)
        if(!ideg[i]) q.push(i);

    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        for(it = e[cur].begin(); it != e[cur].end(); ++it)
        {
            if(!ideg[*it]) continue;
            --ideg[*it];
            if(!ideg[*it]) q.push(*it);
        }
    }

    for(int i = 1; i <= n; ++i)
        if(ideg[i]) return false;
    return true;
}

int main()
{
    int cas, a, b;
    scanf("%d", &cas);
    while(cas--)
    {
        memset(ideg, 0, sizeof(ideg));
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) e[i].clear();
        for(int i = 0; i < m; ++i)
        {
            scanf("%d%d", &a, &b);
            e[a].push_back(b);
            ++ideg[b];
        }
        puts(topo() ? "Correct" : "Wrong");
    }
    return 0;
}
//Last modified :   2015-05-25 09:05

