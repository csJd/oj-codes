#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int july[N], n;
set<int> ans;

int pw[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
//剩余长度, 当前位要填的数，通过什么数来搜索, 路径
void dfs(int len, int d, int bas, int cur)
{
    if(d < 0 || d > 9) return;
    if(!len)
    {
        july[n++] = cur * 10 + d;
        return;
    }
    int k = pw[len - 1];
    dfs(len - 1, d - bas / k, bas % k, cur * 10 + d);
    dfs(len - 1, d + bas / k, bas % k, cur * 10 + d);
}

int main()
{
    ans.insert(7);
    set<int>::iterator it;
    for(int l = 2; l < 10; ++l)
    {
        n = 0;
        for(it = ans.begin(); it != ans.end(); ++it)
            for(int i = 1; i < 10; ++i)
                dfs(l - 1, i, *it, 0);
        for(int i = 0; i < n; ++i) ans.insert(july[i]);
        //printf("%d\n", ans.size());
    }

    int a, b = n = 0;
    for(it = ans.begin(); it != ans.end(); ++it) july[n++] = *it;
    while(~scanf("%d%d", &a, &b))
        printf("%d\n", upper_bound(july, july + n, b) - lower_bound(july, july + n, a));

    return 0;
}
