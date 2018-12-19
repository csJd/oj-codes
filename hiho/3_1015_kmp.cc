#include <cstdio>
#include <cstring>
using namespace std;
const int L = 1e6 + 5;
char s[L], p[L];
int next[L];

void getNext()
{
    int lp = strlen(p);
    int i = 0, j = next[0] = -1;
    while(i <= lp)
    {
        if(j == -1 || p[i] == p[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

int kmp()
{
    int cnt = 0;
    int lp = strlen(p);
    int ls = strlen(s);
    int i = 0;
    int j = 0;
    getNext();
    while(i < ls)
    {
        if(j == -1 || s[i] == p[j])
        {
            ++i;
            ++j;
            if( j >= lp)
            {
                ++cnt;
                j = next[j];
            }
        }
        else
        {
            j = next[j];
        }
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s %s", p, s);
        printf("%d\n", kmp());
    }
    return 0;
}
