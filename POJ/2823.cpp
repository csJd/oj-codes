#include <cstdio>
using namespace std;
const int N = 1e6 + 5;
int a[N], q[N], t[N];
int front, rear, n, k;

#define NOTMONO (!op && a[i] < q[rear - 1]) || (op && a[i] > q[rear - 1])
void getMonoQueue(int op) //op = 0 时单增队列  op = 1 时单减队列
{
    front = rear = 0;
    for(int i = 0; i < n; ++i)
    {
        while( rear > front && (NOTMONO)) --rear;
        t[rear] = i;      //记录滑窗滑到i点的时间
        q[rear++] = a[i];
        while(t[front] <= i - k) ++front;  //保证队首元素在滑窗之内
        if(i > k - 2)
            printf("%d%c", q[front], i == n - 1 ? '\n' : ' ');
    }
}

int main()
{
    while (~scanf("%d%d", &n, &k))
    {
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        getMonoQueue(0); //单增队列维护最小值
        getMonoQueue(1); //单减队列维护最大值
    }

    return 0;
}

//Last modified :   2015-07-06 11:36

