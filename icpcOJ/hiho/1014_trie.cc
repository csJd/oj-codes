#include <cstdio>
using namespace std;

struct Trie
{
    Trie *next[26];
    int cnt;
};

void insertTrie(char *s, Trie *p)
{
    for(int i = 0; s[i]; ++i)
    {
        int j = s[i] - 'a';
        if(p -> next[j] == NULL)
        {
            p -> next[j] = new Trie();
        }
        p = p -> next[j];
        ++(p->cnt);
    }
}

int searchTrie(char *s, Trie *p)
{
    for (int i = 0; p && s[i]; ++i)
    {
        int j = s[i] - 'a';
        p = p -> next[j];
    }
    return p ? p -> cnt : 0;
}

int main()
{
    int n;
    char s[20];
    while(~scanf("%d", &n))
    {
        Trie *root = new Trie();
        while(n--)
        {
            scanf("%s", s);
            insertTrie(s, root);
        }

        scanf("%d", &n);
        while(n--)
        {
            scanf("%s", s);
            printf("%d\n", searchTrie(s, root));
        }
    }
    return 0;
}
