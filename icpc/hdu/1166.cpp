#include<cstdio>
#include<cstring>
using namespace std;
#define lson num*2,s,mid
#define rson num*2+1,mid+1,e
#define mid (s+e)/2
const int N = 50005;
int sum[4 * N];

void pushup(int num)
{
    sum[num] = (sum[num * 2] + sum[num * 2 + 1]);
}

void build(int num, int s, int e)
{
    if(s == e)
    {
        scanf("%d", &sum[num]);
        return;
    }
    build(lson);
    build(rson);
    pushup(num);
}

int query(int num, int s, int e, int l, int r)
{
    if(l == s && e == r) return sum[num];
    if(r <= mid) return query(lson, l, r);
    else if(l > mid) return query(rson, l, r);
    else return query(lson, l, mid) + query(rson, mid + 1, r);
}

void update(int num, int s, int e, int p, int val)
{
    if(s == e && s == p)
    {
        sum[num] += val;
        return;
    }
    if(p <= mid) update(lson, p, val);
    else if(p > mid) update(rson, p, val);
    pushup(num);
}

int main()
{
    int cas, n, a , b;
    char s[10];
    scanf("%d", &cas);
    for(int k=1;k<=cas;++k)
    {
        printf("Case %d:\n",k);
        scanf("%d", &n);
        build(1, 1, n);
        while(scanf("%s", s), s[0] != 'E')
        {
            if(s[0] == 'Q')
            {
                scanf("%d%d", &a, &b);
                printf("%d\n", query(1, 1, n, a, b));
            }
            else if(s[0] == 'A')
            {
                scanf("%d%d", &a, &b);
                update(1, 1, n, a, b);
            }
            else
            {
                scanf("%d%d", &a, &b);
                update(1, 1, n, a, -b);
            }
        }
    }
    return 0;
}
