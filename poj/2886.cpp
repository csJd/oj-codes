#include <cstdio>
#define lc p<<1, s, mid
#define rc p<<1|1, mid + 1, e
#define mid ((s+e)>>1)
using namespace std;
const int N = 5e5 + 5;
int tot[N * 4], val[N];
//totά����Ӧ���仹�ж�����û��ȥ
char name[N][20];

int ip[] = {1, 2, 4, 6, 12, 24, 36, 48, 60, 120, 180, 240, 360, 720,
            840, 1260, 1680, 2520, 5040, 7560, 10080, 15120, 20160,
            25200, 27720, 45360, 50400, 55440, 83160, 110880,
            166320, 221760, 277200, 332640, 498960, 500001
           }; //������

int div[] = {1, 2, 3, 4, 6, 8, 9, 10, 12, 16, 18, 20, 24, 30, 32, 36,
             40, 48, 60, 64, 72, 80, 84, 90, 96, 100, 108, 120,
             128, 144, 160, 168, 180, 192, 200
            };//��������Ӧ��Լ������

void pushup(int p)
{
    tot[p] = tot[p << 1] + tot[p << 1 | 1];
}

void build(int p, int s, int e)
{
    if(s == e)
    {
        tot[p] = 1;
        return;
    }
    build(lc);
    build(rc);
    pushup(p);
}

int update(int p, int s, int e, int x)
{
    int ret;
    if(s == e)
    {
        tot[p] = 0;
        return s;
    }
    if(x <= tot[p << 1]) ret = update(lc, x);
    else ret = update(rc, x - tot[p << 1]);
    pushup(p);
    return ret;
}

int main()
{
    int n, k, m, r, ans, pos;
    while(scanf("%d%d", &n, &k) != EOF)
    {
        build(1, 1, n);
        for(int i = 1; i <= n; ++i)
            scanf("%s%d", name[i], &val[i]);

        for(int i = 0; ip[i] <= n; ++i)
        {
            m = ip[i];   //mΪС�ڵ���n�ĵ�һ��������
            ans = div[i];  //ans��Ӧm��Լ������
        }

        r = n; //��ʣr����
        for(int i = 0; i < m; ++i)
        {
            r--;
            pos = update(1, 1, n, k);
            //posΪʣ���������ŵ�k������ԭʼ�����е�λ��
            if(!r) break;
            if(val[pos] >= 0)   //˳ʱ��
                k = (k - 1 - 1 + val[pos]) % r + 1;
            //��һ��-1�ǰ�1��ʼת��Ϊ0��ʼ
            //�ڶ�����ɾ����k��������λ�ڵ�k-1�� Ҫǰ��val[pos]��
            //�����+1�ǰ�0��ʼ����1��ʼ
            else                //��ʱ��
                k = ((k - 1 + val[pos]) % r + r) % r + 1;
            //��ʱ��ɾ����k�������ڻ�λ�ڵ�k�� Ҫ����-val[pos]��
        }
        printf("%s %d\n", name[pos], ans);
    }

    return 0;
}
//Last modified :   2015-07-13 19:13

