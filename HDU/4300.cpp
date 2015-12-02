#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
char s[N], p[N], cd[30], dcd[30];
int pex[N], sex[N], ls, lp;

void exkmp()
{
    int j = 0, k = 0;
    pex[0] = lp;
    for(int i = 1; i < lp; ++i)
    {
        if(k) j = pex[i - k];
        if(!k || i + j >= k + pex[k])
        {
            if(!k || k + pex[k] <= i) j = 0;
            else j = k + pex[k] - i;
            while(i + j < lp && p[i + j] == p[j]) ++j;
            k = i;
        }
        pex[i] = j;
    }

    j = k = 0;
    for(int i = 0; i < ls; ++i)
    {
        if(k) j = pex[i - k];
        if(!k || i + j >= k + sex[k])
        {
            if(!k || k + sex[k] <= i) j = 0;
            else j = k + sex[k] - i;
            while(j < lp && i + j < ls &&  s[i + j] == p[j]) ++j;
            k = i;
        }
        sex[i] = j;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s%s", cd, p);
        for(int i = 0; i < 26; ++i) dcd[cd[i] - 'a'] = 'a' + i;
        strcpy(s, p);
        ls = lp = strlen(p);
        for(int i = 0; i < ls; ++i)
            s[i] = cd[p[i] - 'a'];
        exkmp();
        int l = (ls + 1) / 2;
        while(l < ls && sex[l] != ls - l) ++l;

        p[l * 2] = 0;
        for(int i = l; i < l * 2; ++i)
            p[i] = dcd[p[i - l] - 'a'];
        puts(p);

    }
    return 0;
}
//Last modified :  2015-10-04 09:15 CST

