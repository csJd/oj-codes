#include <bits/stdc++.h>
using namespace std;
char s[5000], *ps;

int main()
{
    list<int> a, b;
    int l, r, n, v;
    list<int>::iterator it;
    while(~scanf(" [ %d : %d ]%[^\n]", &l, &r, s))
    {
        b.clear();
        ps = s;
        while(sscanf(ps, "%*[^-0-9]%d%n", &v, &n) > 0)
        {
            //过滤掉非'-'和数字再读入一个数
            //n记录scanf读了多少个字符
            ps = ps + n;  //读了n个字符所以要前进n位
            b.push_back(v);
        }

        advance(it = a.begin(), l);
        while(l < r)
        {
            printf("%d%s", *it, l < r - 1 ? ", " : "");
            it = a.erase(it);
            l++;
        }
        puts("");
        a.splice(it, b);
    }
    return 0;
}
//Last modified :   2015-07-24 09:33


//#include <bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//    int n, t;
//    char s[10000];
//    while(~scanf(" %[^\n]%n", s, &n))
//    {
//        printf("%-*s %d 什么鬼%n", 50, s, n, &t);
//        printf("%d\n", t);
//    }
//
//    return 0;
//}
//Last modified :   2015-07-24 09:33

/*
[ 0 : 0] = 1 2 3 4 5 6 7 8 9
[ 1 : 1] = -1
[ 1 : 1] =
[ 0 : 8] = 9 8 7 6 5 4 3 2 1
[ 2 : 8] = -2, -3, -5, -7
[ 0 : 9] = 000
[ 0 : 1] = 1, 2, 8
[ 2 : 2] = 4
[ 0 : 4] =
*/

