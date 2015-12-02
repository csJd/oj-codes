#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int q[N];
int main()
{
    int cas, n, p, cnt, front, rear, i;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d%d", &n, &p);
        for(i = 0; i < n; ++i) scanf("%d", &q[i]);
        cnt = front = 0, rear = n;
        while(front <= p)
        {
            for(i = front + 1; i < rear; ++i)
                if(q[i] > q[front]) break;
            if(i < rear)
            {
                if(front == p) p = rear;
                q[rear++] = q[front];
            }
            else ++cnt;
            ++front;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
