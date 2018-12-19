#include<string.h>
#include<stdio.h>
char s[1100], t[1100], c[1100];
int Min(int a, int b)
{
    return a < b ? a : b;
}
int Max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int lens, lent, i, j, len1, len2;
    while(~scanf("%s%s", s, t))
    {
        lens = strlen(s);
        lent = strlen(t);
        i = j = 0;
        for(i = 0; i <= lent; i++) //s向右移i位与t匹配
        {
            for(j = 0; j < lens; j++)
                if(t[j + i] - '0' + s[j] - '0' > 3)
                    break;
            if(j >= lens)
                break;
        }
        len1 = Max(lent, i + lens);

        for(i = 0; i <= lens; i++)//t向右移i位与s匹配
        {
            for(j = 0; j < lent; j++)
                if(t[j] - '0' + s[j + i] - '0' > 3)
                    break;
            if(j >= lent)
                break;
        }
        len2 = Max(lens, i + lent);
        printf("%d\n", Min(len1, len2));
        memset(s,0,sizeof(s));
        memset(t,0,sizeof(t));
    }
    return 0;
}
/*
//#include<stdio.h>
//#include<string.h>
//char h1[110],h2[110];
//int main()
//{
//    while(scanf("%s%s",h1,h2)!=EOF)
//    {
//        int i,j,t,m,n;
//        int temp,conut1,conut2;
//        i=j=t=0;
//        m=strlen(h1);
//        n=strlen(h2);
//        while(j<m&&i<n)
//        {
//            if(h1[j]+h2[i]-96<=3)
//            {
//                i++,j++;
//            }
//            else
//                t++,i=0,j=t;
//        }
//        conut1=m+n-i;
//        i=j=t=0;
//        while(j<n&&i<m)
//        {
//            if(h2[j]+h1[i]-96<=3)
//            {
//                i++,j++;
//            }
//            else
//                t++,i=0,j=t;
//        }
//        conut2=m+n-i;
//        printf("%d\n",conut1 < conut2 ? conut1 : conut2 );
//    }
//    return 0;
//}
//*/
