#include <bits/stdc++.h>
using namespace std;
const int N = 55, M = 205;
int t[N], d[N][M];  //jʱ����i�ų�վʣ�µ���С�ܵȴ�ʱ��
bool l[N][M], r[N][M];  //jʱ����i�ų�վ�Ƿ�������(��)�ĳ�

int main()
{
    int n, m, ti, cur, cas = 0;

    while(~scanf("%d", &n), n)
    {
        scanf("%d", &ti);
        memset(l, 0, sizeof(l)), memset(r, 0, sizeof(r));
        for(int i = 1; i < n; ++i) scanf("%d", &t[i]);

        scanf("%d", &m);  //curʱ�̳�վj�Ƿ������ҵĳ�
        for(int i = 1; i <= m; ++i)
        {
            scanf("%d", &cur);
            for(int j = 1; j <= n; ++j)
                r[j][cur] = 1, cur += t[j];
        }
        scanf("%d", &m);  //curʱ�̳�վj�Ƿ�������ĳ�
        for(int i = 1; i <= m; ++i)
        {
            scanf("%d", &cur);
            for(int j = n; j >= 1; --j)
                l[j][cur] = 1, cur += t[j - 1];
        }

        memset(d, 0x3f, sizeof(d));
        d[n][ti] = 0;
        for(int j = ti - 1; j >= 0; --j)
        {
            for(int i = 1; i <= n; ++i)
            {
                d[i][j] = d[i][j + 1] + 1;   //��i��վ��1��λʱ��
                if(l[i][j]) d[i][j] = min(d[i][j], d[i - 1][j + t[i - 1]]);  //����
                if(r[i][j]) d[i][j] = min(d[i][j], d[i + 1][j + t[i]]);  //����
            }
        }

        printf("Case Number %d: ", ++cas);
        if(d[1][0] > ti) puts("impossible");
        else printf("%d\n", d[1][0]);
    }
    return 0;
}
