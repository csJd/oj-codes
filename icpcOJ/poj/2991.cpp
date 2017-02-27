#include <cstdio>
#include <cmath>
#define lc p<<1, s, mid
#define rc p<<1|1, mid+1, e
#define mid ((s+e)>>1)
using namespace std;
const int N = 10005;
const double pi = acos(-1.0);
const double eps = 1e-8;
double x[N << 2], y[N << 2], rot[N << 2];
//x 对应区间所有向量的和的横坐标
//y 对应区间所有向量的和的纵坐标
//rot 子节点对应区间所有向量需要逆时针旋转的弧度
double rad[N]; //rad[i] 保存第i个向量和第i+1个向量间的弧度

void rotate(double &x, double &y, double r)
{
    //将向量(x, y)逆时针旋转r弧度
    double xx = x;
    x = xx * cos(r) - y * sin(r);
    y = xx * sin(r) + y * cos(r);
}

void pushup(int p)
{
    x[p] = x[p << 1] + x[p << 1 | 1];
    y[p] = y[p << 1] + y[p << 1 | 1];
}

void pushdown(int p, int s, int e)
{
    if(fabs(rot[p]) < eps) return;
    int lp = p << 1, rp = p << 1 | 1;
    rot[lp] += rot[p];
    rot[rp] += rot[p];
    rotate(x[lp], y[lp], rot[p]);
    rotate(x[rp], y[rp], rot[p]);
    rot[p] = 0;
}

void build(int p, int s, int e)
{
    rot[p] = 0;
    if(s == e)
    {
        scanf("%lf", &y[p]);
        x[p] = 0;
        rad[s] = pi;
        return;
    }
    build(lc);
    build(rc);
    pushup(p);
}

void update(int p, int s, int e, int l, int r, double v)
{
    if(l <= s && e <= r)
    {
        rot[p] += v;
        rotate(x[p], y[p], v);
        return;
    }
    pushdown(p, s, e);
    if(l <= mid) update(lc, l, r, v);
    if(r > mid) update(rc, l, r, v);
    pushup(p);
}

int main()
{
    int n, m, p, first = 1;
    double r;
    while(~scanf("%d%d", &n, &m))
    {
        if(!first) puts("");
        else first = 0;
        build(1, 1, n);
        while(m--)
        {
            scanf("%d%lf", &p, &r);
            r = r / 180 * pi;
            //p与p+1之间的弧度为rad[p] 要达到r p+1还需要逆时针旋转r - rad[p]弧度
            update(1, 1, n, p + 1, n, r - rad[p]);
            rad[p] = r;  //旋转后p与p+1之间的弧度变为r
            printf("%f %f\n", x[1], y[1]); //x[1], y[1]为所有向量和的坐标
        }
    }
    return 0;
}
//Last modified :  2015-08-16 13:00 CST

