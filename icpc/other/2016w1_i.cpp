#include <cstdio>
#include <cstring>
using namespace std;
const int N = 10;
char le[3][N], ri[3][N], res[3][N];

bool suit(char c)
{
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 4; ++j)
            if((le[i][j] == c || ri[i][j] == c) && res[i][0] == 'e')
                return false;
    }
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        for(int i = 0; i < 3; ++i)
            scanf("%s%s%s", le[i], ri[i], res[i]);
        int op = 0;
        char c;
        for(c = 'A'; c <= 'L'; ++c)
        {
            if(suit(c))
            {
                for(int i = 0; i < 3; ++i)
                {
                    if(res[i][0] == 'e') continue;
                    for(int j = 0; j < 4; ++j)
                    {
                        if(le[i][j] == c && res[i][0] == 'u' || ri[i][j] == c && res[i][0] == 'd')
                        {
                            op = 1;
                            i = 3, j = 4;
                        }
                        else if(le[i][j] == c || ri[i][j] == c) i = 3, j = 4;
                    }
                }
                break;
            }
        }
        printf("%c is the counterfeit coin and it is %s.\n", c, op ? "heavy" : "light");
    }
    return 0;
}
