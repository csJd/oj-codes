#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

//void moveit(int n, int a, int b)
//{
//    if(n == 1) return;
//
//    int c = 3 - a - b;
//    moveit(n - 1, a, c);
//    moveit(1, a, b);
//    moveit(n - 1, c, b);
//}

int main()
{
    int n, h[3];
    ll m, t = 1;
    while(scanf("%d%lld", &n, &m), n)
    {
        h[0] = n, h[1] = h[2] = 0;
        int a = 0, b = 1, c = 2;
        while(m)
        {
            while(m < (t << n)) --n;
            h[a] -= n + 1, h[b] += n, ++h[c];
            m = m - (t << n);
            a = b;
            b = c;
            c = 3 - a - b;
        }
        printf("%d %d %d\n", h[0], h[1], h[2]);
    }
    return 0;
}


