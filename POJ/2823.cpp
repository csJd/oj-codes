#include <cstdio>
using namespace std;
const int N = 1e6 + 5;
int a[N], q[N], t[N];
int front, rear, n, k;

#define NOTMONO (!op && a[i] < q[rear - 1]) || (op && a[i] > q[rear - 1])
void getMonoQueue(int op) //op = 0 ʱ��������  op = 1 ʱ��������
{
    front = rear = 0;
    for(int i = 0; i < n; ++i)
    {
        while( rear > front && (NOTMONO)) --rear;
        t[rear] = i;      //��¼��������i���ʱ��
        q[rear++] = a[i];
        while(t[front] <= i - k) ++front;  //��֤����Ԫ���ڻ���֮��
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
        getMonoQueue(0); //��������ά����Сֵ
        getMonoQueue(1); //��������ά�����ֵ
    }

    return 0;
}

//Last modified :   2015-07-06 11:36

