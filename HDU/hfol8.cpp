#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, s1, s2, cas = 0;
    long long d;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld%d%d", &d, &s1, &s2);

        int cnt = 0, f1 = -1;
        for(int i = 0; i < 33; ++i)
        {
             if(d & (1LL << i))
             {
                 ++cnt;              //d中1的个数
                 if(f1 < 0) f1 = i;  //d中从右往左第一个1的位置
             }
        }

        for(int i = cnt < s2 ? 0 : f1; i < 34; ++i)
        {
            if(d & (1LL << i))
            {
                d -= 1LL << i;
                cnt--;
            }
            else
            {
                d |= 1LL << i;
                cnt++;
                break;
            }
        }

        for(int i = 0; i < s1 -cnt; ++i) d |= 1LL << i;
        printf("Case #%d: %lld\n", ++cas, d);
    }
    return 0;
}
//Last modified :  2015-09-27 12:22 CST

