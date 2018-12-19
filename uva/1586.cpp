#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
const int N = 1000;
char s[N], cur;
double m[N], ans;
int main()
{
    int cas, num;
    double ans;
    m['C'] = 12.01, m['H'] = 1.008, m['O'] = 16.00, m['N'] = 14.01, m[0] = 0;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%s", s);
        ans = num = cur = 0;
        for(int i = 0; s[i]; ++i)
        {
            if(isdigit(s[i])) num = num * 10 + s[i] - '0';
            else
            {
                if(num == 0) num = 1;
                ans += m[cur] * num;
                cur = s[i];
                num = 0;
            }
        }
        if(num == 0) num = 1;
        ans += m[cur] * num;

        printf("%.3f\n", ans);
        cur = 0;
    }
    return 0;
}
