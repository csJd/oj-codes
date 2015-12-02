#include<bits/stdc++.h>
using namespace std;
const int N = 200;
int s[N], a[N];
int main()
{
    int n, bot, top, cnt;
    while(~scanf("%d", &n), n)
    {
        bot = 100, top = 99, cnt = 0;
        for(int i = n; i >= 1; --i) s[++top] = i;
        while(cnt < n - 1)
        {
            a[++cnt] = s[top--];
            s[--bot] = s[top--];
        }
        printf("Discarded cards: ");
        for(int i = 1; i < cnt; ++i) printf("%d, ", a[i]);
        printf("%d\n", a[cnt]);
        printf("Remaining card: %d\n", s[top]);
    }
    return 0;
}
