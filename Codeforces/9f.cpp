#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int need[N], rem[N];

int main()
{
    int cur, n, a, t, ans;
	scanf("%d", &n);
	
	cur = 0;
	set<int> rem;
	set<int>::iterator it;
	int cn = 0, cr = 0;
	while(n--)
	{
		scanf("%d", &t);
		if(t == cur) ++cur;

		else if(t < cur)
		{
			if(rem.count(t));
			rem.erase(t);
			rem.insert(t+1);
		}

		else 
		{
			for(int i = cur; i < t; ++i)
			{
				if(rem.empty()) ++ans;
				else
				{
					a = *(rem.begin());
					ans += cur - a;
					rem.erase(a);
				}
			}
			cur = t + 1;
		}

		while(!rem.empty())
		{
			a = *(rem.begin());
			ans += cur - a;
			rem.erase(a);
			++cur;
		}
	}

    return 0;
}
//Last modified :   2015-08-06 12:28 CST
