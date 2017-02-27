#include<stdio.h>
#include<string.h>
char x[2000];
int y[2000][2000];
char z[2000];
int w[2000];
int main()
{
    int i, s, j, k, f, m, q, g, h, t;
    while (gets(x) != NULL)
    {
        memset(w, 0, sizeof(w));
        for(i = m = 0; x[i] != '\0'; ++i)
        {
            if('0' <= x[i] && x[i] <= '9')
                w[m] = w[m] * 10 + x[i] - '0';
            else z[m++] = x[i];
        }

        g = m;
        for (m = 0; m < g; ++m)
        {
            switch (z[m])
            {
            case '*':
                w[m + 1] = w[m] * w[m + 1], w[m] = 0 ;
                break;
            case '/':
                w[m + 1] = 1.0 * w[m] / w[m + 1], w[m] = 0;
                break;
            }
        }


        s = w[0];
        for (m = 0; m < g; ++m)
        {

            switch (z[m])
            {
            case '-':
                while(z[m + 1] == '*' || z[m + 1] == '/') ++m;
                s = s - w[m + 1];
                break;
            default:
                s = s + w[m + 1];
                break;
            }
        }

        printf("%d\n", s);

    }
    return 0;
}
