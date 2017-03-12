#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int L = 1e6 + 10;
char s[L << 1], t[L];
int d[L << 1]; //d[i]记录以i为中心的回文子串在i右边的长度

int manacher()
{
    int ret = 0;
    int j = 0; //记录j + d[j]的最远位置
    d[0] = 0;
    for(int i = 1; s[i]; ++i)
    {
        d[i] = min(d[j * 2 - i], d[j] - (i - j));
        int l = i - d[i];
        int r = i + d[i];
        while(l >= 0 && s[r] && s[l] == s[r])
        {
            --l;
            ++r;
        }
        d[i] = r - 1 - i;
        if(i + d[i] > j + d[j]) j = i;
        if(d[i] > ret) ret = d[i];
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", t);
        s[0] = '@';
        int l = 0;
        for(int i = 0; t[i]; ++i)
        {
            s[++l] = t[i];
            s[++l] = '@';
        }
        s[++l] = 0;

        printf("%d\n", manacher());

    }
    return 0;
}
//Last modified :  2017-03-12 14:57 CST
