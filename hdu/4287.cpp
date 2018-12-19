#include <cstdio>
#include <cstring>
using namespace std;
const int N = 5005;
int trie[N * 6][10], end[N * 6], L;
char num[N][8];

void initTrie()
{
    L = 1;
    memset(trie, 0, sizeof(trie));
    memset(end, 0, sizeof(end));
}

void insertTrie(char s[])
{
    int r = 0, i = 0, j;
    while(s[i])
    {
        j = (s[i] - 'a') / 3 + 2;
        if(s[i] == 's') j = 7;
        if(s[i] == 'v') j = 8;
        if(s[i] > 'x') j = 9;
        ++i;

        if(j > 9) j = 9;
        if(!trie[r][j])
            trie[r][j] = L++;
        r = trie[r][j];
    }
    ++end[r];
}

int searchTrie(char s[])
{
    int r = 0, i = 0, j;
    while(s[i])
    {
        j = s[i++] - '0';
        if(!trie[r][j])
            return 0;
        r = trie[r][j];
    }
    return end[r];
}

int main()
{
    int T, n, m;
    char s[8];
    scanf("%d", &T);
    while(T--)
    {
        initTrie();
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i)
            scanf("%s", num[i]);
        for(int i = 0; i < m; ++i)
        {
            scanf("%s", s);
            insertTrie(s);
        }

        for(int i = 0; i < n; ++i)
            printf("%d\n", searchTrie(num[i]));
    }

    return 0;
}
//Last modified :   2015-07-27 21:15

