#include<cstdio>
#include<cstring>
using namespace std;
const int L = 32, N = 1050;
char s[N];
int ans[L][L], cnt;

void draw(char *s, int &p, int r, int c, int w)
{
    char ch = s[p++];
    if(ch == 'p')
    {
        draw(s, p, r        , c + w / 2, w / 2);
        draw(s, p, r        , c        , w / 2);
        draw(s, p, r + w / 2, c        , w / 2);
        draw(s, p, r + w / 2, c + w / 2, w / 2);
    }
    else if(ch == 'f')
    {
        for(int i = r; i < r + w; ++i)
            for(int j = c; j < c + w; ++j)
                if(ans[i][j] == 0)
                    ans[i][j] = ++cnt;
    }
}

int main()
{
    int cas;
    scanf("%d", &cas);
    while(cas--)
    {
        memset(ans, 0, sizeof(ans));
        cnt = 0;
        for(int i = 0; i < 2; ++i)
        {
            scanf("%s", s);
            int p = 0;
            draw(s, p, 0, 0, L);
        }
        printf("There are %d black pixels.\n", cnt);
    }
    return 0;
}
