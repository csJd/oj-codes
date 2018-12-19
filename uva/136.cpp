#include <cstdio>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;

//priority_queue<ll, vector<ll>, greater<ll> > q;
struct cmp{
    bool operator () (ll a, ll b)    { return a > b; }
};
priority_queue<ll, vector<ll>, cmp> q;


set<ll> cnt;
int ugly[3] = {2, 3, 5};
int main()
{
    ll a, b;
    q.push(1);
    cnt.insert(1);
    for(int i = 1;; ++i)
    {
        a = q.top();
        q.pop();
        if(i == 1500) break;
        for(int j = 0; j < 3; ++j)
        {
            b = a * ugly[j];
            if(!cnt.count(b))
                cnt.insert(b), q.push(b);
        }
    }
    printf("The 1500'th ugly number is %lld.\n", a);
    return 0;
}
