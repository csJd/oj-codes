#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 30;
int n, m, in[N];
char ans[N], q[N];
vector<int> e[N];

int topoSort() //拓扑排序
{
    int d[N], ret = 1;
    memcpy(d, in, sizeof(d));
    int front  = 0, rear = 0, p = 0;
    for(int i = 0; i < n; ++i)
        if(d[i] == 0) q[rear++] = i;
    while(front < rear)
    {
        if(rear - front > 1) ret = 0; //顺序不能确定
        int cur = q[front++];
        ans[p++] = 'A' + cur;
        for(int i = 0; i < e[cur].size(); ++i)
        {
            int j = e[cur][i];
            if((--d[j]) == 0) q[rear++] = j;
        }
    }
    if(p < n) return -1; //有环
    ans[p] = 0;
    return ret;
}

int main()
{
    char a, b;
    while(scanf("%d%d", &n, &m), n || m)
    {
        for(int i = 0; i < n; ++i) e[i].clear();
        memset(in, 0, sizeof(in));
        int flag = 0;
        for(int i = 0; i < m; ++i)
        {
            scanf(" %c<%c", &a, &b);
            if(flag) continue;

            a -= 'A', b -= 'A';
            e[a].push_back(b);
            ++in[b];
            flag = topoSort();
            if(flag == 1)
                printf("Sorted sequence determined after %d relations: %s.\n", i + 1, ans);
            if(flag == -1)
                printf("Inconsistency found after %d relations.\n", i + 1);

        }
        if(!flag) puts("Sorted sequence cannot be determined.");
    }
    return 0;
}
//Last modified :  2015-08-19 10:45 CST

