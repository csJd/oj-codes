#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
const int N = 1000005;
int team[N];

int main()
{
    int cas = 0, n, t, a;
    char cmd[20];
    while(~scanf("%d", &t), t)
    {

        printf("Scenario #%d\n", ++cas);
        for(int i = 0; i < t; ++i)
        {
            scanf("%d", &n);
            while(n--)
                scanf("%d", &a), team[a] = i;
        }

        queue<int> q, qt[1005];
        while(scanf("%s", cmd), cmd[0] != 'S')
        {
            if(cmd[0] == 'E')
            {
                scanf("%d", &a);
                t = team[a];
                if(qt[t].empty()) q.push(t);
                qt[t].push(a);
            }
            else
            {
                t = q.front();
                printf("%d\n", qt[t].front()), qt[t].pop();
                if(qt[t].empty()) q.pop();
            }
        }
        puts("");
    }
    return 0;
}
