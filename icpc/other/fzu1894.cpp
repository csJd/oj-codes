#include <cstdio>
using namespace std;
const int N = 1e6 + 5;
int rp[N], q[N];
int main()
{
    int T, n, front, rear, i, t;
    char s[20];
    scanf("%d", &T);
    while(T--)
    {
        //求最大值用递减队列
        i = front = rear = t = 0;
        while(scanf("%s", s), s[0] != 'E')
        {
            if(s[0] == 'C')
            {
                scanf("%s %d", s, &rp[i]);
                while(front < rear && rp[q[rear-1]] < rp[i]) --rear;
                q[rear++] = i;
                i++;
            }

            else if(s[0] == 'Q')
            {
                while(q[front] < t && front < rear) ++front;
                printf("%d\n", rear > front ? rp[q[front]] : -1);
            }

            else if(s[0] == 'G') t++;
        }
    }
    return 0;
}
//Last modified :   2015-07-06 14:45
