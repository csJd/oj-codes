#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
char s1[N], s2[N], s3[N];
int n, t, p[N];

int main()
{
    while(~scanf("%d%d", &n, &t))
    {
        scanf("%s%s", s1, s2);
        int same = 0, diff = 0;
        for(int i = 0; i < n; ++i)
        {
            if(s1[i] == s2[i])
            {
                ++same;
                s3[i] = s1[i];
            }
            else p[diff++] = i;
        }

        if((diff + 1) / 2 > t) puts("-1");  //至少要产生(diff + 1) / 2 对不同
        else
        {
            int i = 0, j, k;
            //不同的位置至多产生diff组不同  t - same为还需要由不同位置产生多少组
            while(diff > 1 && diff > t - same)
            {
                diff -= 2;
                --t;
                j = p[i++];
                k = p[i++];
                s3[j] = s1[j];
                s3[k] = s2[k];
            }

            t -= diff;
            while(diff--)
            {
                k = p[i++];
                s3[k] = 'a' + (s1[k] - 'a' + 1) % 26;
                if(s3[k] == s2[k]) s3[k] = 'a' + (s2[k] - 'a' + 1) % 26;
            }

            for(int i = 0; t && i < n; ++i)
            {
                if(s1[i] == s2[i])
                {
                    --t;
                    s3[i] = s1[i] == 'a' ? 'y' : 'a';
                }
            }

            puts(s3);
        }
    }
    return 0;
}
/*
3 1
bcb
bca
*/
//bcc
//Last modified :  2015-10-07 01:11 CST


