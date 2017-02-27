#include <bits/stdc++.h>
using namespace std;
set<int> s;
int main()
{
	int n, a, m;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d", &a);
		if(s.count(a))
		{
			s.erase(a);
			++a;
		}
		s.insert(a);
		m = a;
	}
	printf("%d\n", m - s.size());
    
    return 0;
}
//Last modified :   2015-08-06 17:24 CST
