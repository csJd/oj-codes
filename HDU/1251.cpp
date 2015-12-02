#include <cstdio>
#include <cstring>
using namespace std;
const int N = 5e5;
int n;
struct Trie
{
    int chi[26], cnt;
    Trie()
    {
        memset(chi, 0, sizeof(chi));
        cnt = 0;
    }
} trie[N];

void insertTrie(char s[])
{
    int r = 0;
    for(int i = 0; s[i]; ++i)
    {
        int j = s[i] - 'a';
        if(trie[r].chi[j] == 0)
            trie[r].chi[j] = n++;
        r = trie[r].chi[j];
        ++trie[r].cnt;
    }
}

int query(char s[])
{
    int r = 0;
    for(int i = 0; s[i]; ++i)\
    {
        int j = s[i] - 'a';
        if(trie[r].chi[j] == 0)
            return 0;
        r = trie[r].chi[j];
    }
    return trie[r].cnt;
}

int main()
{
    n = 1;
    char s[15];
    while(gets(s))
    {
        if(!s[0]) break;
        insertTrie(s);
    }
    while(gets(s))
    {
        if(!s[0]) break;
        printf("%d\n", query(s));
    }
    return 0;
}
//Last modified :   2015-07-27 10:42
