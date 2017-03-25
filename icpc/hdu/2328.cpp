#include <bits/stdc++.h>
using namespace std;
const int N = 30005;
int trie[N][26], cnt[N], L;
char s[N];

void initTrie()
{
    L = 1;
    memset(cnt, 0, sizeof(cnt));
    memset(trie, 0, sizeof(trie));
}

int insertTrie(char s[], int id)
{
    int r = 0, i = 0, len = 0, j;
    while(s[i])
    {
        j = s[i++] - 'a';
        if(!trie[r][j])
        {
            if(id == 1) trie[r][j] = L++;
            else break;  //在第一个串中都没有的就不用管了
        }
        r = trie[r][j];
        if(cnt[r] + 1 >= id) cnt[r] = id; //当前前缀出现过的次数
        else break;
        ++len;   //当前前缀的长度
    }
    return len;
}

int main()
{
    int n;
    while(scanf("%d", &n), n)
    {
        initTrie();
        int len = 0;
        char ans[N] = "IDENTITY LOST", t[N];
        for(int i = 1; i <= n; ++i)
        {
            scanf("%s", s);
            for(int j = 0; s[j]; ++j)
            {
                int k = insertTrie(s + j, i);
                if(!k || i < n) continue;
                strncpy(t, s + j, k), t[k] = 0;
                if(k > len || (k == len && strcmp(ans, t) > 0))
                    strcpy(ans, t), len = k;
            }
        }
        puts(ans);
    }
    return 0;
}
//Last modified :  2015-10-05 14:40 CST

