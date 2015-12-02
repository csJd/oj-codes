#include <bits/stdc++.h>
using namespace std;
int a[6];
int main()
{
    int ans, s;
    for(int i = 0; i < 6; ++i)
        scanf("%d", &a[i]);

        s = a[1] + a[2] + a[0];
        ans = s*s - a[0]*a[0] - a[2]*a[2] - a[4]*a[4];

    printf("%d\n", ans);
    return 0;
}
//Last modified :   2015-07-22 22:42


