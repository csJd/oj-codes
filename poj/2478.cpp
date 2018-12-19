#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;

int phi[N], pme[N];
bool vis[N];
ll s[N];

void getPhi()
{
	int m = 0;
	for(int i = 2; i < N; ++i)
	{
		if(!vis[i]) pme[m++] = i, phi[i] = i - 1;
		for(int j = 0; j < m && pme[j] * i < N; ++j)
		{
			int k = pmi[j] * i;
			vis[k] = 1;
			if( i % pme[j] == 0)
			{
				phi[k] = phi[i] * pme[j]; //k相对i来说p[j]的指数又增加了1
				break;
			}
			else phi[k] = phi[i] * (pme[j] - 1);  //i 和 pme[j]互质 利用积性函数性质
		}
	}
}

int main()
{
	int n;
	for(int i = 2; i < N; ++i) s[i] = s[i-1] + phi[i];
	while(scanf("%d", &n), n)
		printf("%lld\n", s[n]);
	return 0;
}
		
