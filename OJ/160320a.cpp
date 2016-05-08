#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;
const int N = 105;
char s[N], cd[N];

bool kind()
{
    int i = 0;
    while(isalpha(s[++i]));
    while(isdigit(s[++i]));
    return s[i];
}


int main()
{
    int T, r, c, i;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", s);
        r = c = 0;
        switch (kind())
        {
        case 0:

            for(i = 0; isalpha(s[i]); ++i)
                c = c * 26 + s[i] - 'A' + 1;
            while (s[i])
                r = r * 10 + s[i++] - '0';
            printf("R%dC%d\n", r, c);
            break;

        case 1:
            int i;
            for(i = 1; isdigit(s[i]); ++i)
                r = r * 10 + s[i] - '0';
            while (s[++i])
                c = c * 10 + s[i] - '0';
            int top = 0;
            c = c;
            while(c)
            {
                if(c % 26)
                {
                    cd[top++] = 'A' + c % 26 - 1;
                    c /= 26;
                }
                else
                {
                    cd[top++] = 'Z';
                    c = c / 26 - 1;
                }
            }
            while(top) putchar(cd[--top]);
            printf("%d\n", r);
            break;
        }

    }
    return 0;
}
