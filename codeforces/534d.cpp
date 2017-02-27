#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int q[N], n;
stack<int> s[N];

int main()
{
    int a;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a), s[a].push(i);

    int p = 0, i = 0;
    while(1)
    {
        if(!s[i].empty())  q[p++] = s[i++].top();
        else
        {
            if(i < 3) break;
            s[--i].pop(), s[--i].pop(), s[--i].pop();
        }
    }
    if(p == n)
    {
        puts("Possible");
        for(int i = 0; i < n - 1; ++i)
            printf("%d ", q[i]);
        printf("%d\n", q[n - 1]);
    }
    else puts("Impossible");

    return 0;
}
//Last modified :   2015-04-13 01:57

