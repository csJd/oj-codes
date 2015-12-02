#include <cstdio>
using namespace std;
const int N = 2e5 + 5;
int q[N], v[N];

int main()
{
    int m, d, a, t, n;
    int front, rear;
    char s[10];
    while(~scanf("%d%d", &m, &d))
    {
        front = rear = n = t = 0;
        while(m--)
        {
            scanf("%s %d", s, &a); //求区间最大用递减队列
            if(s[0] == 'A')
            {
                v[n] = (a + t) % d;
                while(front < rear && v[q[rear - 1]] < v[n]) --rear;
                q[rear++] = n++;
            }

            else  //二分在查询区间内最靠近队首的数
            {
                int le = front, ri = rear - 1, mid;
                while(le <= ri)
                {
                    mid = (le + ri) >> 1;
                    if(q[mid] < n - a)
                        le = mid + 1;
                    else ri = mid - 1;
                }
                t = v[q[ri + 1]];
                printf("%d\n", t);
            }
        }
    }
    return 0;
}
//Last modified :   2015-07-06 15:51
