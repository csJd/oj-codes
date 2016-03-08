#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    while(~scanf("%d%d", &a, &b))
    {
        int t = 0;
        while(a > 0 && b > 0)
        {
            if(a >= b && a >= 2) a -= 2, b += 1;
            else if(b > a && b >= 2) b -= 2, a += 1;
            else break;
            ++t;
        }
        printf("%d\n", t);
    }
    return 0;
}
//Last modified :  2016-03-07 17:11 CST

