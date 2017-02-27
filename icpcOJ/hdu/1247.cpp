#include <cstdio>
#include <cstring>
using namespace std;
const int N = 50005;
int n;
char ss[N][20];

struct Trie
{
    int chi[26];
    bool isEnd;
    Trie()
    {
        isEnd = false;
        memset(chi, 0, sizeof(chi));
    }
} dic[N];

void insertTrie(char s[])
{
    int r = 0, i = 0, j;
    while(s[i])
    {
        j = s[i++] - 'a';
        if(!dic[r].chi[j])
            dic[r].chi[j] = ++n;
        r = dic[r].chi[j];
    }
    dic[r].isEnd = true;
}

bool searchTrie(char s[])
{
    int r = 0, i = 0, j;
    while(s[i])
    {
        j = s[i++] - 'a';
        r = dic[r].chi[j];
        if(dic[r].isEnd && s[i])
        {
            int rr = 0, ii = i;
            while(s[ii])
            {
                j = s[ii] - 'a';
                if(!dic[rr].chi[j]) break;
                rr = dic[rr].chi[j];
                ++ii;
            }
            if(!s[ii] && dic[rr].isEnd)
                return true;
        }
    }
    return false;
}

int main()
{
    int m = n = 0;
    while(~scanf("%s", ss[m]))
        insertTrie(ss[m++]);

    for(int i = 0; i < m; ++i)
        if(searchTrie(ss[i])) puts(ss[i]);

    return 0;
}

//#include <cstdio>
//#include <cstring>
//using namespace std;
//const int N = 50005;
//int n;
//char ss[N][50];
//
//struct Trie
//{
//    Trie *chi[26];
//    bool isEnd;
//    Trie()
//    {
//        isEnd = false;
//        memset(chi, NULL, sizeof(chi));
//    }
//}*root;
//
//void insertTrie(Trie *r, char s[])
//{
//    int i = 0, j;
//    while(s[i])
//    {
//        j = s[i++] - 'a';
//        if(r->chi[j] == NULL)
//            r->chi[j] = new Trie();
//        r = r->chi[j];
//    }
//    r->isEnd = true;
//}
//
//bool searchTrie(Trie *r, char s[], int op)
//{
//    int i = 0, j;
//    while(s[i])
//    {
//        j = s[i++] - 'a';
//        if(r->chi[j] == NULL)
//            return false;
//        r = r->chi[j];
//        if(!op && r->isEnd && s[i])
//        {
//            if(searchTrie(root, s + i, 1))
//                return true;
//        }
//    }
//    return op ? r->isEnd : op;
//}
//
//int main()
//{
//    root = new Trie();
//    int m = 0;
//    while(~scanf("%s", ss[m++]))
//        insertTrie(root, ss[m - 1]);
//
//    for(int i = 0; i < m; ++i)
//        if(searchTrie(root, ss[i], 0)) puts(ss[i]);
//
//    return 0;
//}

