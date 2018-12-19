#include <cstdio>
using namespace std;

char s[100005];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        bool flag = true;
        scanf("%s", s);
        for(int i = 1; s[i]; ++i)
            if(s[i] == '#' && s[i - 1] == '#')
                flag = false;
        puts(flag ? "yes" : "no");
    }

    return 0;
}
//Last modified :  2016-04-10 13:25 CST

