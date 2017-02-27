#include <cstdio>
#include <cstring>
using namespace std;
const int N = 26;
int tp[N][N], in[N], n;
char ans[N];

void topoSort(int k)
{
    if(k == n)
    {
        ans[k] = 0;
        puts(ans);
        return;
    }

    for(int i = 0; i < N; ++i)
    {
        if(in[i] == 0)
        {
            ans[k] = i + 'a';
            in[i] = -1;
            for(int j = 0; j < N; ++j)
                if(tp[i][j]) --in[j];

            topoSort(k + 1);

            in[i] = 0;
            for(int j = 0; j < N; ++j)
                if(tp[i][j]) ++in[j];
        }
    }
}

int main()
{
    char a, b, c, flag = 1;
    while(~scanf(" %c%c", &a, &c))
    {
        memset(in, -1, sizeof(in));
        memset(tp, 0, sizeof(tp));

        in[a - 'a'] = 0;
        n = 1;
        while(c != '\n')
        {
            scanf(" %c%c", &a, &c);
            in[a - 'a'] = 0;
            ++n;
        }

        while(scanf(" %c%*c%c%c", &a, &b, &c))
        {
            tp[a - 'a'][b - 'a'] = 1;
            ++in[b - 'a'];
            if(c == '\n') break;
        }

        if(flag) flag = 0;
        else puts("");
        topoSort(0);
    }
    return 0;
}
//Last modified :  2015-08-20 10:39 CST

