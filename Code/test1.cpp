#include <stdio.h>
#include <string.h>
int atoi(char like[]);
int main()
{
    char buffer[32];
    while (gets(buffer) != NULL)
    {
        printf("%d\n", atoi(buffer));
    }
    return 0;
}
int atoi(char like[])
{
    long long  x = 0, a = 1;
    int l = strlen(like);
    int x1 = 0, x2 = 0, k = 0;
    for(int i = l - 1; i >= 0; i--)
    {
        if(like[i] == ' ')
            like[i] = '\0';
        else
            break;
    }
    l = strlen(like);
    for(int i = 0; i < l; i++)
    {
        if(like[i] == '+')
            x1++;
        if(like[i] == '-')
            x2++;
        if(like[i] != '+' && like[i] != '-' && (like[i] < '0' || like[i] > '9') && like[i] != ' ')
            return 0;
    }
    if(x1 + x2 >= 2)
        return 0;
    for(int i = 0, k = 0; i < l; i++)
    {
        if((like[i] == '-' || like[i] == '+') && k != 0)
            return 0;
        if(like[i] == ' ' && k != 0)
            return 0;
        if(like[i] == '-')
        {
            a = -a;
            k++;
        }
        if(like[i] >= '0' && like[i] <= '9')
        {
            x = (x * 10) + (like[i] - '0');
            k++;
        }

        if(x > 2147483647 && a < 0) return -2147483648;
        if(x > 2147483646 && a > 0) return 2147483647;
    }
    if(a < 0)
        x = -x;
    return x;
}
