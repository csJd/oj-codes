#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
using namespace std;

typedef set<int> Set;
map<Set, int> id;
vector<Set> Setcache;

int getID(Set x)
{
    if(id.count(x)) return id[x];
    Setcache.push_back(x);
    return id[x] = Setcache.size() - 1;
}

int main()
{
    stack<int> s;
    char op[20];
    int cas, n;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d", &n);
        while(n--)
        {
            scanf("%s", op);
            if(op[0] == 'P') s.push(getID(Set()));
            else if(op[0] == 'D') s.push(s.top());
            else
            {
                Set x1 = Setcache[s.top()];
                s.pop();
                Set x2 = Setcache[s.top()];
                s.pop();
                Set x;
                if(op[0] == 'U') set_union (ALL(x1), ALL(x2), INS(x));
                if(op[0] == 'I') set_intersection (ALL(x1), ALL(x2), INS(x));
                if(op[0] == 'A') x = x2, x.insert(getID(x1));
                s.push(getID(x));
            }
            printf("%d\n", Setcache[s.top()].size());
        }
        puts("***");
    }
    return 0;
}
