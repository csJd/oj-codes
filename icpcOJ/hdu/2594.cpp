#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int nex[N], l;
char p[N];

void getNext()
{
    int i = 0, j = nex[0] = -1;
    while(i < l)
    {
        if(j == -1 || p[i] == p[j])
            nex[++i] = ++j;
        else j = nex[j];
    }
}

int main()
{
    while(~scanf("%s", p))
    {
        int l1 = strlen(p), l2;
        scanf("%s", p + l1);
        l = strlen(p), l2 = l - l1;
        getNext();
        while(l > l1 || l > l2) l = nex[l];
        if(l > 0)
        {
            p[l] = 0;
            printf("%s ", p);
        }
        printf("%d\n", l);
    }
    return 0;
}
//Last modified :  2015-09-24 21:39 CST

