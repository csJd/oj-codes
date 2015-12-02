#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e6 + 5;
int trie[N][26], cnt[N], id[N], L;

void insertTrie(char s[], int iid)
{
    int r = 0, i = 0, j;
    while(s[i])
    {
        j = s[i++] - 'a';
        if(!trie[r][j])
            trie[r][j] = L++;
        r = trie[r][j];
        if(id[r] != iid) ++cnt[r];
        id[r] = iid;//��ǵ�ǰǰ׺id ��֤������ͬ����ֻ����һ��
    }
}

int searchTrie(char s[])
{
    int r = 0, i = 0, j;
    while(s[i])
    {
        j = s[i++] - 'a';
        if(!trie[r][j])
            return 0;
        r = trie[r][j];
    }
    return cnt[r];
}

int main()
{
    L = 1;//��ʼ��Trie
    char s[30];
    int p, q;
    scanf("%d", &p);
    for(int i = 1; i <= p; ++i)
    {
        scanf("%s", s); //����s�����к�׺
        for(int j = 0; s[j]; ++j)
            insertTrie(s + j, i);
    }

    scanf("%d", &q);
    while(q--)
    {
        scanf("%s", s);
        printf("%d\n", searchTrie(s));
    }

    return 0;
}
//Last modified :   2015-07-28 08:23

