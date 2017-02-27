#include<cstdio>
#include<cstring>
using namespace std;
const int N = 15;
char a[N], b[N];
int c[N], pos, n;

void tran(int x)
{
    if(x == 0) return;
    tran(x / 2);
    if(x % 2 == 1)
        c[pos++] = 1;
    else
        c[pos++] = 0;
}

int main()
{
    int va, vb, unk, cnt;
    scanf("%s%s", a, b);
    int l = strlen(a);
    va = vb = unk = 0;
    for(int i = 0; i < l; ++i)
    {
        va = (a[i] == '+' ? va + 1 : va - 1);
        if(b[i] == '+') ++vb;
        else if(b[i] == '-') --vb;
        else ++unk;
    }
    int n = (1 << unk);
    double ans;
        for(int i = cnt = 0; i < n; ++i)
        {
            int st = pos = 11 - unk;
            memset(c, 0, sizeof(c));
            tran(i);
            int k = 0;
            for(int j = st; j < 11; ++j)
                k = c[j] ? k + 1 : k - 1;
            if(k == va - vb) ++cnt;
        }
        ans = cnt * 1.0 / n;
    printf("%.12lf", ans);
    return 0;
}
