#include <bits/stdc++.h>
using namespace std;

/*struct cmp{
    bool operator () (int a, int b)    {  return a > b;}
};
priority_queue<int, vector<int>, cmp> q;*/
priority_queue<int, vector<int>, greater<int> > q;

int main()
{
    int a, b, n, ans;
    while(~scanf("%d", &n), n)
    {
        ans = 0;
        while(n--) scanf("%d", &a), q.push(a);
        while(1)
        {
            a = q.top(), q.pop();
            b = q.top(), q.pop();
            ans += (a + b);
            if(q.empty()) break;
            q.push(a + b);
        }
        printf("%d\n", ans);
    }
    return 0;
}
