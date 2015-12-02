#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
const int N = 10005;
set<int> p;
int v[N], a, b;

void initPrime(int n)
{
    memset(v, 0, sizeof(v));
    for(int i = 2; i * i < n; ++i)
    {
        if(!v[i])
        {
            for(int j = i; i * j < n; ++j)
                v[i * j] = 1;
        }
    }
    for(int i = 1000; i < n; ++i)
        if(!v[i]) p.insert(i);
}

int bfs()
{
    queue<int> q;
    memset(v, 0, sizeof(v));
    v[a] = 1;
    q.push(a);
    int t, c;
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        if(t == b) return v[t];
        for(int i = 0; i < 4; ++i)
            for(int j = 0; j < 10; ++j)
            {
                c = 1;
                for(int k = 0; k < i; ++k) c *= 10;
                c = (t / (c * 10)) * c * 10 + j * c + t % c;
                if((!v[c]) && p.count(c))
                {
                    v[c] = v[t] + 1;
                    q.push(c);
                }
            }
    }
    return 0;
}

int main()
{
    int ans;
    initPrime(N);
    while(~scanf("%d%d", &a, &b))
    {
        if(ans = bfs()) printf("%d\n", ans - 1);
        else puts("Impossible");
    }
    return 0;
}

