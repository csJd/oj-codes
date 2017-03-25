#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int cnt[26];
    char in[5000];
    int T;
    scanf("%d ", &T);
    while(T--)
    {
        memset(cnt, 0, sizeof(cnt));
        gets(in);
        for(int i = 0; in[i]; ++i)
            if(in[i] >= 'a' && in[i] <= 'z')
                ++cnt[in[i] - 'a'];
        int ans = 0;
        for(int i = 0; i < 26; ++i)
            if(cnt[i]) ++ans;
        printf("%d\n", ans);
    }
    return 0;
}

