#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1000005;
char s[N];
int nex[N], ans[N], l;

void getNext()
{
    int i = 0, j = nex[0] = -1;
    while(i < l)
    {
        if(j == -1 || s[i] == s[j])
            nex[++i] = ++j;
        else j = nex[j];
    }
}

int main()
{
    int T, cas = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", s);
        l = strlen(s);
        getNext();
        int n = 0, k = nex[l];
        while(k >= 0)
        {
            ans[n++] = l - k;
            k = nex[k];
        }

        printf("Case #%d: %d\n", ++cas, n);
        for(int i = 0; i < n; ++i)
            printf("%d%c", ans[i], i < n - 1 ? ' ' : '\n');
    }
    return 0;
}
//Last modified :  2015-10-06 13:32 CST

