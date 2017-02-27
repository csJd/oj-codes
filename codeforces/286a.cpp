#include<cstdio>
#include<cstring>
using namespace std;
const int N = 20;
char s[N], p[N];
int l;
bool ispal()
{
    for(int i = 0; i < (l + 1) / 2; ++i)
        if(p[i] != p[l - i]) return false;
    return true;
}

int main()
{
    int i, j, k;
    scanf("%s", s);
    l = strlen(s);
    for(char c = 'a'; c <= 'z'; ++c)
    {
        for(k = 0; k <= l; ++k)
        {
            i = j = -1;
            while(i < k - 1) p[++j] = s[++i];
            p[++j] = c;
            while(i < l - 1) p[++j] = s[++i];
            if(ispal())
            {
                printf("%s\n", p);
                return 0;
            }
        }
    }
    printf("NA\n");
    return 0;
}
