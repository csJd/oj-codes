#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1000;
char s[N];
int main()
{
    int k, t, ans;
    scanf("%d", &k);
    while(k--)
    {
        ans = t = 0;
        scanf("%s", s);
        for(int i = 0; s[i]; ++i)
        {
            if(s[i] == 'O') ans += (++t);
            else t = 0;
        }
        printf("%d\n", ans);
    }
    return 0;
}
