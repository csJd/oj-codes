#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 40005;
int l[N];

int main()
{
    int T, a, p;
    scanf("%d", &T);
    while(T--)
    {
        memset(l, -1, sizeof(l));
        scanf("%d", &p);
        int top = 0;
        while(p--)
        {
            scanf("%d", &a);
            int k = lower_bound(l, l + top, a) - l;
            if(k == top) ++top;
            l[k] = a;
        }
        printf("%d\n", top);
    }
    return 0;
}
