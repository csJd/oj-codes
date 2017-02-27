#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
double x[3], y[3];

double len(int i, int j)
{
	double dx = x[i] - x[j], dy = y[i] - y[j];
	return sqrt(dx * dx + dy * dy);
}

int main()
{
	int T, cas;
	double h, rad, a, b, c, ans;
	scanf("%d", &T);
	while(T--)
	{
		for(int i = 0; i < 3; ++i)
			scanf("%lf%lf", &x[i], &y[i]);
		a = len(1, 2);
		b = len(0, 2);
		c = len(0, 1);
		rad = acos((b*b + c*c - a*a) / (2 * b * c));
		ans = b * rad + b * cos(rad / 2);
	}
    return 0;
}
//Last modified :  2015-09-26 15:00 CST
