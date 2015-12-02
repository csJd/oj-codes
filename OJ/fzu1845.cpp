#include <cstdio>
using namespace std;
const int N = 1e5 + 5;
int h[N], s[N], l[N];
int main()
{
    int n, top;
    while(~scanf("%d", &n))
    {
        for(int i = 1; i <= n; ++i)
            scanf("%d", &h[i]);

        top = 0; //找第一个大于的用递减栈
        for(int i = n; i > 0; --i)
        {
            while(top && h[s[top - 1]]  <= h[i]) --top;
            l[i] = top ? s[top - 1] : 0;
            s[top++] = i;
        }

        for(int i = 1; i <= n; ++i)
            printf("%d\n", l[i]);
    }
    return 0;
}
//Last modified :   2015-07-06 13:20
