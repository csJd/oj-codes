#include <bits/stdc++.h>
using namespace std;
typedef vector<int>::iterator it;
class CountryGroup
{
public:
    int solve(vector<int> a)
    {
        int ans = 0, t, c;
        for(it i = a.begin(); i != a.end();++i)
        {
            c = t = *i;
            while(--t)
            {
                ++i;
                if(i == a.end() || *i != c)
                {
                    ans = -1;
                    break;
                }
            }
            if(ans == -1) break;
            ++ans;
        }
        return ans;
    }
};
