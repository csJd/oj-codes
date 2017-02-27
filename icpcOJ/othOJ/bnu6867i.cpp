#include <bits/stdc++.h>
using namespace std;

int main()
{
	int w1, l1, w2, l2; 
	while(~scanf("%d%d%d%d", &w1, &l1, &w2, &l2))
	{
		int n = w1 / w2, m = l1 / l2;
		int ans = n * m;

		int rw = w1 - n * w2, rl = l1 - m * l2;
		int dw = w2 / rw, dl = l2 / dl;

		if(rw) ans += m / dw + m % dw ? 1 : 0;
		if(rl) ans += n / dl + n % dl ? 1 : 0;
		if(m % dw == 0 && n % dl == 0) ++ans;
	}
    return 0;
}
//Last modified :  2015-10-04 12:49 CST
