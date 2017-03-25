#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100005;
int a[N], b[N];

int main()
{
    a[0] = b[0] = 0;
    a[1] = b[1] = 1;
    for(int i = 2; i < N ; ++i)
    {
        if(i % 2 == 0) a[i] = a[i / 2];
        else a[i] = a[i / 2] + a[i / 2 + 1];
        b[i] = a[i] > b[i-1] ? a[i] : b[i-1];
    }

    int n;
    while(~scanf("%d", &n), n)
        printf("%d\n", b[n]);
}
