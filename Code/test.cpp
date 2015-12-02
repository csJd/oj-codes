#include<stdio.h>
int main()
{
    static int n, i, j, a[1000];
    while(scanf("%d", &n) != EOF)
    {
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
            {
                if(j % i == 0)
                {
                    if(a[j])
                        a[j] = 0;
                    else
                        a[j] = 1;
                }
            }
        j = 0;
        for(i = 1; i <= n; i++)
        {
            if(a[i] == 1)
                j++;
        }
        printf("%d\n", j);
    }
    return 0;
}
