#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

struct Job
{
    int t, s, id;
    bool operator< (const Job &j)
    {
        return t * s + (t + j.t) * j.s < (j.t * j.s) + ( t + j.t) * s;
    }
} job[N];

int main()
{
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d%d", &job[i].t, &job[i].s), job[i].id = i + 1;
        sort(job, job + n);
        for(int i = 0; i < n; ++i)
            printf("%d%c", job[i].id, i < n - 1 ? ' ' : '\n');
        if(T) puts("");
    }
    return 0;
}
//Last modified :  2015-08-17 16:10 CST

