#include <cstdio>
#include <algorithm>
using namespace std;
const int L = 1e6 + 10;
char s[L << 1], t[L];
int d[L << 1]; //d[i]记录以i为中心的回文子串在i右边的长度

int manacher()
{
    int ret = 0; //最长回文字串的长度
    int j = 0; //记录j + d[j]的最远位置
    for(int i = 1; s[i]; ++i)
    {
        d[i] = min(d[j * 2 - i], d[j] - (i - j));
        while(i - d[i] && s[i + d[i] + 1] == s[i - d[i] - 1]) ++d[i];
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
        s[0] = 'y';
        int l = 0;
        for(int i = 0; t[i]; ++i)
        {
            s[++l] = t[i];
            s[++l] = 'y';
        }
        s[++l] = 0;
        printf("%d\n", manacher());
    }
    return 0;
}
//Last modified :  2017-03-13 10:02 CST
