#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[3], b[3], aa, bb;
    for(int i = 0; i < 3; ++i)
        scanf("%d%d", &a[i], &b[i]);
    int flag = 0;
    aa = a[1] + a[2];
    bb = max(b[1], b[2]);
    if((aa <= a[0] && bb <= b[0]) || (bb <= a[0] && aa <= b[0])) flag = 1;

    aa = a[1] + b[2];
    bb = max(b[1], a[2]);
    if((aa <= a[0] && bb <= b[0]) || (bb <= a[0] && aa <= b[0])) flag = 1;

    aa = b[1] + b[2];
    bb = max(a[1], a[2]);
    if((aa <= a[0] && bb <= b[0]) || (bb <= a[0] && aa <= b[0])) flag = 1;

    aa = b[1] + a[2];
    bb = max(a[1], b[2]);
    if((aa <= a[0] && bb <= b[0]) || (bb <= a[0] && aa <= b[0])) flag = 1;


    puts(flag ? "YES" : "NO");
    return 0;
}
//Last modified :   2015-07-22 22:18

