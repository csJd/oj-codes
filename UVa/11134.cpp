#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int xl[N], yl[N], xr[N], yr[N], x[N], y[N], n;

bool solve(int a[], int l[], int r[])
{
    int cur, mr;
    //mrΪ����k��������С�ҽ磬curΪ��k����������
    memset(a, -1, sizeof(int)*n);
    for(int k = 1; k <= n; ++k)
    {
        cur = -1, mr = N;
        for(int i = 0; i < n; ++i)
            if(a[i] < 0 && l[i] <= k && r[i] < mr)
            //ѡk������ʱ1~k-1�������Ѿ�ѡ���� ����ֻ�ÿ����ҽ�
                mr = r[cur = i];
        if(cur < 0 || k > mr)  return 0;
        a[cur] = k;
    }
    return 1;
}

int main()
{
    while(~scanf("%d", &n), n)
    {
        for(int i = 0; i < n; ++i)
            scanf("%d%d%d%d", &xl[i], &yl[i], &xr[i], &yr[i]);

        if(solve(x, xl, xr) && solve(y, yl, yr))
            for(int i = 0; i < n; ++i)
                printf("%d %d\n", x[i], y[i]);
        else puts("IMPOSSIBLE");
    }
    return 0;
}
