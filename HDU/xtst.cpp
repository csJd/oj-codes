#include <bits/stdc++.h>
#define lc p<<1, s, mid
#define rc p<<1|1, mid+1, e
#define mid ((s+e)>>1)
using namespace std;
const int N = 200005;
int maxv[N * 4], minv[N * 4], add[N * 4];

void pushup(int p)
{
    maxv[p] = max(maxv[p << 1], maxv[p << 1 | 1]);
    minv[p] = min(minv[p << 1], minv[p << 1 | 1]);
}

void pushdown(int p)
{
    int l = p << 1;
    int r = p << 1 | 1;

    if(add[p])
    {
        add[l] += add[p];
        add[r] += add[p];
        minv[l] += add[p];
        minv[r] += add[p];
        maxv[l] += add[p];
        maxv[r] += add[p];
        add[p] = 0;
    }

    //子区间的所有值肯定都父区间的minv~maxv之间
    minv[l] = max(minv[l], minv[p]);
    minv[l] = min(minv[l], maxv[p]);
    maxv[l] = max(maxv[l], minv[p]);
    maxv[l] = min(maxv[l], maxv[p]);

    minv[r] = max(minv[r], minv[p]);
    minv[r] = min(minv[r], maxv[p]);
    maxv[r] = max(maxv[r], minv[p]);
    maxv[r] = min(maxv[r], maxv[p]);
}

void build(int p, int s, int e)
{
    if(s == e)
    {
        scanf("%d", &maxv[p]);
        minv[p] = maxv[p];
        return;
    }
    build(lc);
    build(rc);
    pushup(p);
}

void update(int p, int s, int e, int l, int r, int v, int op)
{
    if(s >= l && e <= r)
    {
        if(op == 1) //将[l,r]区间的所有值都加上v
        {
            add[p] += v;
            minv[p] += v;
            maxv[p] += v;
        }
        else if (op == 2)  //将[l,r]区间中所有大于v的值都改为v
        {
            maxv[p] = min(maxv[p], v);
            minv[p] = min(minv[p], v);
        }
        else  //op = 3  将[l,r]区间中的所有小于v的值都改为v
        {
            maxv[p] = max(v, maxv[p]);
            minv[p] = max(v, minv[p]);
        }
        return;
    }
    pushdown(p);
    if(l <= mid) update(lc, l, r, v, op);
    if(r > mid) update(rc, l, r, v, op);
    pushup(p);
}

int query(int p, int s, int e, int l, int r, int op)
{
    if(s == l && e == r)//op = 0 时查询最小值  op = 1 时查询最大值
        return op ? maxv[p] : minv[p];
    pushdown(p);
    if(r <= mid) return query(lc, l, r, op);
    if(l > mid) return query(rc, l, r, op);
    if(op) return max(query(lc, l, mid, op), query(rc, mid + 1, r, op));
    return min(query(lc, l, mid, op), query(rc, mid + 1, r, op));
}

int main()
{
    int T, n, q, l, r, op, c, ax, in;
    scanf("%d", &T);
    while(T--)
    {
        memset(add, 0, sizeof(add));
        scanf("%d%d", &n, &q);
        build(1, 1, n);
        while(q--)
        {
            scanf("%d%d%d", &op, &l, &r);
            if(op == 4)
            {
                ax = query(1, 1, n, l, r, 1);
                in = query(1, 1, n, l, r, 0);
                printf("%d %d\n", in, ax);
            }
            else
            {
                scanf("%d", &c);
                update(1, 1, n, l, r, c, op);
            }
        }
    }
    return 0;
}


/*
4

1 1
1
4 1 1

3 3
1 2 3
4 1 3
3 2 3 5
4 1 3

3 11
1 2 3
4 1 3
2 2 3 0
4 1 3
1 1 2 1
4 1 3
1 1 3 1
4 1 3
2 1 3 0
4 1 3
3 2 3 5
4 1 3
*/
//Last modified :   2015-06-07 17:36

