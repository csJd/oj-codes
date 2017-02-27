#include <cstdio>
using namespace std;
const int N = 1e6+5;
typedef long long ll;
int h[N], hest[i];
ll s[N], add[N], st[N];

int main()
{
	int T, n;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		ll ans = 0, add;
		int top = 0;
		for(int i = 1; i <= n;++i)
		{
			scanf("%d", &h[i]);
			s[i] = s[i - 1] + h[i];
			while(top && h[i] >= h[st[top-1]])
			{
				--top;
				ans -= add[st[top]];
			}

			if(top)
			{
				ll hh = min(s[i], s[st[top-1]]);
				int ww = i - st[top -1] - 1;
				add[i] = hh * ww - s[i-1] + s[st[top-1]];
			}
			else add[i] = 0;
			st[top++] = i;
		}

		for(int i = 0; i < top; ++i)
			ans += add[st[i]];

		printf("%lld\n", ans);
	}
    return 0;
}
//Last modified :  2016-04-10 13:32 CST
