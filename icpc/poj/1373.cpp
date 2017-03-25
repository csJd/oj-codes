#include<cstdio>
#include<cstring>
using namespace std;
char s0[][8] = {"*@@@@@*", "*@***@*", "*@***@*", "*@***@*", "*@***@*", "*@@@@@*"};
char s1[][8] = {"***@***", "*@@@***", "***@***", "***@***", "***@***", "*@@@@@*"};
int main()
{
    int n, ans[16], cnt;
    while(scanf("%d", &n), n)
    {
        cnt = 0;
        while(n)
        {
            ans[++cnt] = n % 2;
            n /= 2;
        }
        for(int i = 0; i < 6; ++i)
        {
            for(int j = cnt; j > 0; --j)
                if(ans[j]) printf("%s", s1[i]);
                else printf("%s", s0[i]);
            printf("\n");
        }
    }
    return 0;
}
