#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e6 + 5, M = 10005;
int s[N], p[M], nex[M], n, m;

int kmp()
{
    int i = 0, j = nex[0] = -1;
    //make next
    while(i < m)
    {
        if(j == -1 || p[i] == p[j])
            nex[++i] = ++j;
        else j = nex[j];
    }

    //kmp
    i = j = 0;
    while(j < m && i < n)
    {
        if(j == -1 || s[i] == p[j])
        {
            ++i, ++j;
            if(j == m) return i - j + 1;
        }
        else j = nex[j];
    }
    return -1;
}


int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i)
            scanf("%d", &s[i]);
        for(int j = 0; j < m; ++j)
            scanf("%d", &p[j]);
        printf("%d\n", kmp());
    }
    return 0;
}
//Last modified :   2015-07-28 09:48

