#include<stdio.h>
#define num 5
int main()
{
    int a[num], b[num], i, j, t, k;
    for(i = 0; i < num; i++)
    {
        scanf("%d", &a[i]);
        b[i] = i;
    }

    for(j = 0; j < num; j++)
        b[j] = i;
    for(i = 0; i < num; i++)
    {
        for(j = 0; j < num - 1; j++)
        {
            if(a[j] >= a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    for(i = 0; i < num; i++)
        for(j = 0; j < num; j++)
            if(b[j] == a[i])
                b[i] = j;
    for(i = 0; i < num; i++)
        printf("%d ", a[i]);
    printf("\n");
    for(j = 0; j < num; j++)
        printf("%d ", b[j]);
    return 0;
}
