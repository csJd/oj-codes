#include <cstdio>
#include <string>
#include <map>
using namespace std;
map<string, int> rev;

int main()
{
    int n, m, k;
    char s[15][20];
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%s", s[i]);
            rev[s[i]] = 0;
        }

        char pgive[20], pget[20];
        for(int i = 0; i < n; ++i)
        {
            scanf("%s %d %d", pgive, &m, &k);
            if(k)
            {
                rev[pgive] += m % k - m;
                m = m / k;
            }

            for(int j = 0; j < k; ++j)
            {
                scanf("%s", pget);
                rev[pget] += m;
            }
        }

        for(int i = 0; i < n; ++i)
        {
            printf("%s %d\n", s[i], rev[s[i]]);
        }
    }

    return 0;

}

/*
红包的收益
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
如你所知，中国素来有发红包的习俗。
新年要到了，小明想要知道朋友圈里每个人的收益。
每个人有mi数量的钱用来发红包，并且这笔钱会平均地发给ki个人（收益得到的钱不再发红包）。
而且发给每个人的钱都是整数。如果不能整除，发红包的人保留mi mod ki的钱。

输入
第1行，一个整数n，2<=n<=10，小明的n个朋友。
第 2到n+1行每行一个字符串，第i+1行表示第i个人的名字。
接下来n段：
每段第一行是一个字符串，表示发红包的人的名字。
第二行为两个数mi,ki。含义如上。
接下来ki行，每行一个字符串表示被发红包的人的名字。

输出
n行，每行一个字符串和一个整数，分别表示第i个人的名字和收益。


样例输入
5
dave
laura
owen
vick
amr
dave
200 3
laura
owen
vick
owen
500 1
dave
amr
150 2
vick
owen
laura
0 2
amr
vick
vick
0 0

样例输出
dave 302
laura 66
owen -359
vick 141
amr -150
*/
