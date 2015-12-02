#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, n, b;
	while(~scanf("%d%d", &n, &a))
	{
		priority_queue<int> pq;
		for(int i = 1; i < n; ++i)
		{
			scanf("%d", &b);
			if(b >= a) pq.push(b);
		}

		int ans = 0;
		while(!pq.empty && pq.top() > a)
		{
			b = pq.top();
			pq.pop();
			++a;
			++ans;
			pq.push(b - 1);
		}

		printf("%d\n", ans);
	}
    return 0;
}
//Last modified :  2015-08-30 00:42 CST
