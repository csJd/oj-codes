#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
char s[N];
int l, p[N];

int manacher()
{
    for(int i = l; i > 0; --i)
    {
        s[i * 2] = '#';
        s[i * 2 - 1] = s[i - 1];
    }
    l = l * 2 + 1, s[l] = 0, s[0] = '#';

    int k = 0, ret = 0;
    for(int i = 0; i < l; ++i)
    {
        p[i] = i > k * 2 ? 1 : min(p[k * 2 - i], k + p[k] - i);
        while(i >= p[i] && s[i - p[i]] == s[i + p[i]]) ++p[i];
        if(i + p[i] > k + p[k]) k = i;
        if(p[i] > ret) ret = p[i];
    }
    return ret - 1;
}

int main()
{
    while(~scanf("%s", s))
    {
        l = strlen(s);
        printf("%d\n",  manacher());
    }
    return 0;
}
//Last modified :  2015-10-06 16:45 CST

