#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1505;
int cnt[N], n, m, ans;

struct route
{
    int start, interval, times;
    route() {}
    route(int s, int i, int t): start(s), interval(i), times(t) {}
    bool operator< (const route &r) const {
        return times > r.times;
    }
} r[N];

bool ok(int time, int inter)
{
    while(time < 60)
    {
        if(!cnt[time]) return false;
        time += inter;
    }
    return true;
}

//�ӵ�k����·��ʼƥ�� ��ǰ�Ѿ�ƥ��num����¼  ����sum��������·
void dfs(int k, int num, int sum)
{
    if(num == n)
    {
        if(sum < ans) ans = sum;
        return;
    }

    for(int i = k; i < m; ++i)
    {
        if(sum + (n - num) / r[i].times >= ans) return;
        //��֦ r�ǰ������Ӵ�С�����  �������ٻ���Ҫ(n - num) / r[i].times����·
        if(!ok(r[i].start, r[i].interval)) continue;
        for(int j = r[i].start; j < 60; j += r[i].interval) --cnt[j];
        dfs(i, num + r[i].times, sum + 1);
        //i֮ǰ����·֮ǰ�Ѿ���������
        for(int j = r[i].start; j < 60; j += r[i].interval) ++cnt[j]; //����
    }
}

int main()
{
    int t;
    while(~scanf("%d", &n))
    {
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; ++i)
            scanf("%d", &t), ++cnt[t]; //��¼ÿ��ʱ�̳��ֶ��ٹ���

        m = 0;//������ʱ��iΪ�װ�  ������ʱ��Ϊj����������Ĺ�����·
        for(int i = 0; i < 30; ++i)
            for(int j = i + 1; j < 60 - i; ++j)
                if(ok(i, j)) r[m++] = route(i, j, 1 + (59 - i) / j);

        sort(r, r + m);
        ans = 17;
        dfs(0, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
//Last modified :   2015-08-02 13:39

