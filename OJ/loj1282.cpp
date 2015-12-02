#include <cstdio>
#include <cmath>
using namespace std;
const int LE = 1000;

int suf(int n, int k)
{
	n = n % LE;
	int ret = 1;
	while(k)
	{
		if(k & 1) 
			ret = ret * n % LE;
		n = n * n % LE;
		k >>= 1;
	}
	return ret;
}

int main()
{
	int T, n, k, pre, cas = 0;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &k);
		int pre = (int)pow(10, 2 + fmod(log10(n) * k, 1));
		printf("Case %d: %d %03d\n", ++cas, pre, suf(n, k));
	}

    return 0;
}
//Last modified :   2015-08-06 09:45 CST
