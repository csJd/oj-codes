#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1000000;
char a[N], b[N];
int main()
{
    while(~scanf("%s%s", a, b))
    {
        int i = 0, j = 0, la = strlen(a), lb = strlen(b);
        while(j < lb && i < la)
        {
            while(j < lb && a[i] != b[j]) ++j;
            if(a[i] == b[j]) ++i, ++j;
        }
        if(i >= la) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
