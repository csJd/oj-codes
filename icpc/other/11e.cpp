#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1005;
int s[N];

int main()
{
    int T, cas, a, n, ans;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &cas, &n, &s[0]);

        for(int i = 1; i < n; ++i)
        {
            scanf("%d", &a);
            s[i] = s[i - 1] + a;
        }

        for(int i = 0; i < n; ++i)
        {
            int j = i;
            ans = s[i];
            while(j < n - 1)
            {
                int le = j + 1, ri = n - 1, mid;
                while(le <= ri)
                {
                    mid = (le + ri) >> 1;
                    if(s[mid] - s[j] >= ans)
                        ri = mid - 1;
                    else le = mid + 1;
                }
                if(s[ri + 1] - s[j] == ans) j = ri + 1;
                else break;
            }
            if(j == n - 1) break;
        }
        printf("%d %d\n", cas, ans);
    }
    return 0;
}
