#include <bits/stdc++.h>
using namespace std;

int main()
{
	double ans, a, b, c;
	while(~scanf("%lf%lf%lf", &c, &a, &b))
	{
		ans = a / (a + b) * c;
		printf("%f\n", ans);
	}
    return 0;
}
//Last modified :  2015-10-25 16:57 CST
