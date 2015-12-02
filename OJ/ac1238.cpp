#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 100;
 
char s1[N];
char s2[N + N];
bool f1,f2;
int main()
{
//    freopen("test0.in","r",stdin);
//    freopen("test0.out","w",stdout);
    int t,i,j;
    scanf("%d",&t);
    while(t --)
    {
        scanf("%s",s1);
        int len = strlen(s1);
        f1 = f2 = false;
        if(s1[0] == '-')
        {
            f1 = true;
            j = 1;
        }
        else
            j = 0;
        for(i = 0;i < len;i ++)
            if(s1[i] == 'e' || s1[i] == 'E')
            {
                if(s1[i + 1] == '-')
                {
                    f2 = true;
                    i ++;
                }
                i ++;
                break;
            }
        int nb = 0;
        for(;i < len;i ++)
            nb = nb * 10 + s1[i] - '0';
        if(f2)
            nb *= -1;
        int p;
        for(i = 0;i < len;i ++)
            if(s1[i] == '.')
            {
                p = i;
                break;
            }
        if(s1[0] == '-')
            p --;
        for(i = 0;;j ++,i ++)
        {
            if(s1[j] == 'e' || s1[j] == 'E')
                break;
            if(s1[j] == '.')
            {
                i --;
                continue;
            }
            s2[i] = s1[j];
        }
        s2[i] = 0;
        //puts(s2);
        p += nb;
        //printf("p:%d\n",p);
        char ans[N + N];
        int k = 0;
        if(f1)
            ans[k ++] = '-';
        if(p <= 0)
        {
            ans[k ++] = '0';
            ans[k ++] = '.';
            for(j = 2;j <= (-p) + 1;j ++)
                ans[k ++] = '0';
 
            for(j = 0;j < i;j ++)
                ans[k ++] = s2[j];
        }
        else if(p < i)
        {
            for(j = 0;j < p;j ++)
                ans[k ++] = s2[j];
            ans[k ++] = '.';
            for(;j < i;j ++)
                ans[k ++] = s2[j];
        }
        else
        {
            for(j = 0;j < i;j ++)
                ans[k ++] = s2[j];
            for(;j < p;j ++)
                ans[k ++] = '0';
        }
        ans[k] = 0;
        if(ans[0] == '-')
            i = 1;
        else
            i = 0;
        while(isdigit(ans[i]))
        {
            if(ans[i] != '0')
                break;
            else if(ans[i + 1] != '.')
                    ans[i] = 0;
            i ++;
        }
        for(i = 0;i < k;i ++)
            if(ans[i])
                putchar(ans[i]);
        putchar(10);
    }
    return 0;
}
