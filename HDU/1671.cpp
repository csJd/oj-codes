#include <cstdio>
#include <cstring>
using namespace std;
const int N = 10005;
char tel[N][12];
int trie[N * 10][10], L;
bool end[N * 10], flag;

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
        if(end[r]) flag = false;
        j = s[i++] - '0';
        if(!trie[r][j])
            trie[r][j] = L++;
        r = trie[r][j];
    }
    for(int i = 0; i < 10; ++i)
        if(trie[r][i]) flag = false;
    end[r] = true;
}

bool searchTrie(char s[])
{
    int r = 0, i = 0, j;
    while(s[i])
    {
        if(end[r]) return false;
        j = s[i++] - '0';
        r = trie[r][j];
    }
    return true;
}

int main()
{
    int T, n;
    scanf("%d", &T);

    while(T--)
    {
        initTrie();
        scanf("%d", &n);
        flag = true;
        for(int i = 0; i < n; ++i)
        {
            scanf("%s", tel[i]);
            insertTrie(tel[i]);
        }

        puts(flag ? "YES" : "NO");
    }

    return 0;
}
//Last modified :   2015-07-27 16:56
