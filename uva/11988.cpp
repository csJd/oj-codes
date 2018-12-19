#include<cstdio>
#include<cstring>
using namespace std;
const int N=100005;
char s[N];
int next[N];
int main()
{
    int last,cur;
    while(~scanf("%s",s+1))
    {
        next[0]=last=cur=0;
        int length=strlen(s+1);
        for(int i=1;i<=length;++i)
        {
            if(s[i]=='[') cur=0;
            else if(s[i]==']') cur=last;
            else
            {
                next[i]=next[cur];
                next[cur]=i;
                if(cur==last) last=i;
                cur=i;
            }
        }
        for(int i=next[0];i;i=next[i])
            printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}
