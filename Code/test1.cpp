#include <stdio.h>
int main ()
{
    int a[20], n, m, k;
    while (scanf ("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf ("%d", &a[i]);
        scanf ("%d %d", &m, &k);
        for (int i = 0; i < n; i++)
            if (m >= a[i] && m <= a[i + 1])
            {
                n++;
                for (int j = n - 1; j > i + 1; j--)
                    a[j] = a[j - 1];
                a[i + 1] = m;
                break;
            }
        for (int i = 0; i < n; i++)
        {
            if (i < n - 1)
                printf ("%d ", a[i]);
            else
                printf ("%d\n", a[i]);
        }
        printf ("%d", a[k]);
    }
    return 0;
}
