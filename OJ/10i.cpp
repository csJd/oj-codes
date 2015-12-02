#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int h, m;
    while(~scanf(" %d : %d", &h, &m))
    {
        if(h < 0 || h > 11 || m < 0 || m > 59)
        {
            puts("That is a joke.");
            continue;
        }
        h = 12 - h - 1;
        m = 60 - m;
        if(m == 60) h++, m = 0;
        if(h == 12) h = 0;
        printf("%02d:%02d\n", h, m);
    }
    return 0;
}
//Last modified :  2015-08-11 13:55 CST

