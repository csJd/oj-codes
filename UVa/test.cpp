#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int p, q, r, s, t, u;

double func(double x)
{
	return p * exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}


int main()
{
	while(~scanf("%d%d%d%d%d%d", &p, &q, &r,&s, &t,&u))
	{
		double le = 0, ri = 1, mid;
		while(le + eps < ri)
		{
			mid = (le + ri) / 2;
			if(func(mid) > 0) le = mid;
			else ri = mid;
		}
		if(fabs(func(ri)) < eps) printf("%.4f\n",ri);
		else puts("No solution");
	}
    return 0;
}
//Last modified :  2015-08-17 08:48 CST
