#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void matMul(LL A[][],LL B[][],LL C[][])
{
	memset(C,0,sizeof(C));
	for(int i=0;i<n;++i)
		for(int j=0; j<n; ++j)
			for(int k=0; k<n; ++k)
				C[i][j]+=A[i][k]*B[k][j];
}

void matPow(LL A[][],int k)
{
	int ret[n][n]={0},cur[n][n];
	memcpy(cur,A,sizeof(A));
	for(int i=0;i<n;++i) ret[i][i] = 1;
	while(k)
	{
		if(k&1)
		{
			tmp = matMul(
		}


int main()
{
	while(~scanf("%d",&t))
	{
		ll A[2][2]={0,1,1,1};
		matPow(A,t);
		printf("%lld\n",A[0][1]+A[1][1]);
	}
    return 0;
}
//Last modified :   2015-04-13 13:02
