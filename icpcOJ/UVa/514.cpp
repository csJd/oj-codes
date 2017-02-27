#include<cstdio>
#include<cstring>
using namespace std;
const int N = 2000;
int b[N], c[N];
int main()
{
    int l, cur, top;
    while(scanf("%d", &l), l)
    {
        while(scanf("%d", &b[1]), b[1])
        {
            for(int i = 2; i <= l; ++i)
                scanf("%d", &b[i]);
            cur = 1, top = 0;
            for(int i = 1; i <= l; ++i)
            {
                if(i == b[cur]) cur++;
                else c[++top] = i;
                while(top && b[cur] == c[top])
                {
                    ++cur;
                    --top;
                }
            }
            printf("%s\n", top ? "No" : "Yes");
        }
        printf("\n");
    }
    return 0;
}
