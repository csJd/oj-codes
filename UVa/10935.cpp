#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int s[N], a[N];
int main()
{
    int n, cnt, bot, top;
    while(~scanf("%d", &n), n)
    {
        bot = top = 100;
        cnt = 0;
        for(int i = n; i >= 1; --i)
            s[top++] = i;
        while(cnt < n - 1)
        {
            a[++cnt] = s[--top];
            s[--bot] = s[--top];
        }
        printf("Discarded cards:");
        if(cnt)
        {
            printf(" ");
            for(int i = 1; i < cnt; ++i) printf("%d, ", a[i]);
            if(cnt) printf("%d\n", a[cnt]);
        }
        else printf("\n");
        printf("Remaining card: %d\n", s[--top]);
    }
    return 0;
}

