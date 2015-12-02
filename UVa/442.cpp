#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;
const int N = 1000;
int st[N], row[N], col[N], r[N], c[N];

int main()
{
    int n, ans, top;
    scanf("%d", &n);
    char na[3], s[N];
    for(int i = 1; i <= n; ++i)
    {
        scanf("%s", na);
        int j = na[0] - 'A';
        scanf("%d%d", &row[j], &col[j]);
    }

    while(~scanf("%s", &s))
    {
        int i;
        for(i = 0 ; i < 26; ++i)
            c[i] = col[i], r[i] = row[i];
        ans = top = 0;

        for(i = 0; s[i] != '\0'; ++i)
        {
            if(isalpha(s[i]))
            {
                int j = s[i] - 'A';
                st[++top] = j;
            }

            else if(s[i] == ')')
            {
                if(r[st[top]] != c[st[top - 1]])  break;
                else
                {
                    --top;
                    c[st[top]] = c[st[top + 1]];
                    ans += (r[st[top]] * c[st[top]] * r[st[top + 1]]);
                }
            }
        }
        if(s[i] == '\0') printf("%d\n", ans);
        else printf("error\n");
    }
    return 0;
}
