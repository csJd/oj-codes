#include <cstdio>
#include <vector>
#include <algorithm>
#define lc p<<1, s, mid
#define lp p<<1
#define rc p<<1|1, mid + 1, e
#define rp p<<1|1
#define mid ((s+e)>>1)
using namespace std;
const int N = 50005;
int len[N << 2], lle[N << 2], lri[N << 2], setv[N << 2];

struct Block //内层块结构体
{
    int l, r;
    bool operator< (const Block &b) const{
        return l < b.l;
    }
} block;
vector<Block> vb;
vector<Block>::iterator it;

void pushup(int p, int s, int e)
{
    len[p] = max(len[lp], len[rp]);
    len[p] = max(len[p], lri[lp] + lle[rp]);
    lle[p] = lle[lp], lri[p] = lri[rp];
    if(lle[p] == mid - s + 1) lle[p] += lle[rp];
    if(lri[p] == e - mid)  lri[p] += lri[lp];
}

void pushdown(int p, int s, int e)
{
    if(setv[p] == -1) return;
    setv[lp] = setv[rp] = setv[p];
    len[lp] = lle[lp] = lri[lp] = setv[p] * (mid - s + 1);
    len[rp] = lle[rp] = lri[rp] = setv[p] * (e - mid);
    setv[p] = -1;
}

void build(int p, int s, int e)
{
    setv[p] = -1;
    if(s == e)
    {
        len[p] = lle[p] = lri[p] = 1;
        return;
    }
    build(lc);
    build(rc);
    pushup(p, s, e);
}

void update(int p, int s, int e, int l, int r, int v)
{
    if(l <= s && e <= r)
    {
        setv[p] = v;
        len[p] = lle[p] = lri[p] = v * (e - s + 1);
        return;
    }
    pushdown(p, s, e);
    if(l <= mid) update(lc, l, r, v);
    if(r > mid) update(rc, l, r, v);
    pushup(p, s, e);
}

int query(int p, int s, int e, int v)
{
    if(s == e) return s;
    pushdown(p, s, e);
    if(len[lp] >= v) return query(lc, v);
    if(lri[lp] + lle[rp] >= v) return mid + 1 - lri[lp];
    return query(rc, v);
}

int main()
{
    int n, m, x, p;
    char op[10];
    while(~scanf("%d%d", &n, &m))
    {
        build(1, 1, n);
        vb.clear();
        while(m--)
        {
            scanf("%s", op);

            if(op[0] == 'R') //Reset
            {
                update(1, 1, n, 1, n, 1); //用build会TLE
                vb.clear();
                puts("Reset Now");
            }

            if(op[0] == 'N')  //New
            {
                scanf("%d", &x);
                if(len[1] < x) puts("Reject New");
                else
                {
                    p = query(1, 1, n, x);
                    printf("New at %d\n", p);
                    update(1, 1, n, p, p + x - 1, 0);

                    block.l = p;
                    block.r = p + x - 1;
                    it = upper_bound(vb.begin(), vb.end(), block);
                    //找到第一个起点大于p的位置 确保插入后还是升序的
                    vb.insert(it, block);
                }
            }

            if(op[0] == 'G')  //Get
            {
                scanf("%d", &x);
                if(x > vb.size()) puts("Reject Get");
                else printf("Get at %d\n", vb[x - 1].l);
            }

            if(op[0] == 'F') //Free
            {
                scanf("%d", &x);
                block.l = block.r = x;
                it = upper_bound(vb.begin(), vb.end(), block);
                int i = it - vb.begin() - 1;
                if(i < 0 || vb[i].r < x) puts("Reject Free");
                else
                {
                    printf("Free from %d to %d\n", vb[i].l, vb[i].r);
                    update(1, 1, n, vb[i].l, vb[i].r, 1);
                    vb.erase(--it);
                }
            }
        }
        puts("");
    }
    return 0;
}
//Last modified :  2015-08-16 15:24 CST

