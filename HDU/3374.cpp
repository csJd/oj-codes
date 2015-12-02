#include <bits/stdc++.h>
using namespace std;
const int N = 2000005;
int nex[N], l;
char s[N];

void getNext()
{
    int i = 0, j = nex[0] = -1;
    while(i < l)
    {
        if(j == -1 || s[i] == s[j])
            nex[++i] = ++j;
        else j = nex[j];
    }
}

int getPos(bool op) //op = 0最小表示法  op = 1 最大表示法
{
    strncpy(s + l, s, l);
    int i = 0, j = 1;
    while(i < l && j < l)
    {
        int k = 0;
        while(k < l && s[i + k] == s[j + k]) ++k;
        if(k >= l) break;
        if((s[i + k] > s[j + k]) ^ op) i += k + 1;
        else j += k + 1;
        if(i == j) ++j;  //保证i != j
    }
    return i < j ? i : j;
}

int main()
{
    while(~scanf("%s", s))
    {
        l = strlen(s);
        getNext();
        int rl = l - nex[l], t = l % rl ? 1 : l / rl;
        int p0 = getPos(0) + 1, p1 = getPos(1) + 1;
        printf("%d %d %d %d\n", p0, t, p1, t);
    }
    return 0;
}
//Last modified :  2015-10-05 18:30 CST

