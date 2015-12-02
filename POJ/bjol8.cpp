#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
double x[N], num[N];

int main()
{
	double det = 0.25;
	x[0] = 0;
	for(int i = 1; i < 500; ++i)
	{
		x[i] = x[i-1] + det;
		det /= 2.0;
	}

	int T;
	double p;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lf", &p);
		int le = 0, ri = 499, mid;
		while(le <= ri)
		{
		    mid = (le + ri) >> 1;
			if(x[mid] < p)
				le = mid + 1;
			else ri = mid - 1;
		}
		if(x[ri + 1] > p)
			printf("%d\n", 4 * (ri + 1));
		else puts("-1");
	}
    return 0;
}
//Last modified :  2015-09-20 12:20 CST

