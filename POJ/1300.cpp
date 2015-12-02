#include<cstdio>
#include<cstring>
#include<cctype>
const int N = 21;
using namespace std;

int main()
{
    int door, cnt, m, n, deg[N];
    char s[N], c;
    while(~scanf("%s", s), strcmp(s, "ENDOFINPUT"))
    {
        memset(deg, 0, sizeof(deg));
        door = cnt = 0;
        scanf("%d %d\n", &m, &n);
        for(int i = 0; i < n; ++i)
        {
            while(scanf("%c", &c))
            {
                if(isdigit(c)) ++door, ++deg[i], ++deg[c - '0'];
                else if(c == ' ') continue;
                else break;
            }
            if(deg[i] % 2) ++cnt;
        }

        scanf("%s", s);
        bool ok = (cnt == 0 && m == 0 ) || (m && cnt == 2 && deg[m] % 2 );
        if(ok) printf("YES %d\n", door);
        else printf("NO\n");
    }
    return 0;
}

