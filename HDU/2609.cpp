#include <bits/stdc++.h>
using namespace std;
const int N = 205;
char s[N];
int l, n, p;

int getMin()
{
    int i = 0, j = 1;
    while(i < l && j < l)
    {
        int k = 0;
        while(k < l && s[i + k] == s[j + k]) ++k;
        if(k >= l) break;
        if(s[i + k] > s[j + k]) i += k + 1;
        else j += k + 1;
        if(i ==j) ++j;
    }
    return i < j ? i : j;
}

int main()
{
    while(~scanf("%d", &n))
    {
        set<string> cnt;
        while(n--)
        {
            scanf("%s", s);
            l = strlen(s);
            strncpy(s + l, s, l);
            p = getMin();
            for(int i = 0; i < l; ++i)
                s[i] = s[i + p];
            s[l] = 0;
            cnt.insert(s);
        }
        printf("%d\n", cnt.size());
    }
    return 0;
}
//Last modified :  2015-10-06 11:20 CST

