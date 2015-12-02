#include<cstdio>
int a[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isleap(int y)
{
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}
int main()
{
    int cas, y, m, d;
    scanf("%d", &cas);
    while(cas--)
    {
        a[2] = 28;
        scanf("%d-%d-%d", &y, &m, &d);
        if(isleap(y)) a[2] = 29;
        if(m < 1 || m > 12 || d < 1 || d > a[m]) printf("v^v\n");
        else printf("^v^\n");
    }
    return 0;
}
