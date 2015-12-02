#include <cstdio>
#include <cmath>
using namespace std;
const double dom=100000,eps=1e-8;
int a,b,c,x,y;
double getr(double i){
	return sqrt((x-i)*(x-i)+(a*i*i+b*i+c-y)*(a*i*i+b*i+c-y));
}

int main()
{
	while(~scanf("%d%d%d%d%d",&a,&b,&c,&x,&y))
	{
		double l=x-dom, r=x+dom, m,mm;
		while(l+eps<r)
		{
			m = (l+r)/2, mm = (m+r)/2;
			if(getr(m)<getr(mm)) r=mm;
			else l=m;
		}
		printf("%.3f\n", getr(m));
	}
    return 0;
}
//Last modified :   2015-04-10 13:32
