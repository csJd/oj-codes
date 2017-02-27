#include<stdio.h>
int a[100], b[100], c[100], f[100];
int r[1000000];
int main()
{
    int n, t, i, j, k, t0, tmax, flag;
    while (scanf("%d%d", &n, &t) != EOF)
    {
        if (n == 0 && t == 0)
            break;
        for ( i = 0; i < n; i++)
            scanf("%d%d%d", &a[i], &b[i], &c[i]);

        k = 0;
        int start = tmax = 0;
        for (i = 0; i <= t; i++)
        {
            flag = 1;
            for (j = 0; j < n; j++)
            {
                f[j] = a[j] * i * i + b[j] * i + c[j];
                if (f[j] < 0)
                {
                    flag = 0;
                    break;
                }
            }

            if (flag == 0)  //
            {
                if(i - 1 - start > tmax)
                    tmax = i - 1 - start ;
                start = i + 1;
            }
        }

        if (!k)
            printf("Unhappy\n");
        else
        {
            t0 = 0;
            tmax = 1;
            for (i = 1; i < k; i++)
            {
                if (r[k] - r[k - 1] == 1) t0++;
                else
                {
                    if (t0 > tmax) tmax = t0;
                    t0 = 0;
                }
            }
            if (tmax == t)
                printf("Cannot Stop\n");
            else
                printf("%d\n", tmax);
        }
    }
    return 0;
}
