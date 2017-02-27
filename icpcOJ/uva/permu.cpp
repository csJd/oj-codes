#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100000;

void print(int n, int *a, int cur)
{
    if(cur == n)
    {
        for(int i = 0; i < n; ++i) printf("%d ", a[i]);
        printf("\n");
    }
    else
        for(int i = 1; i <= n; ++i)
        {
            int ok = 1;
            for(int j = 0; j < cur; ++j)
                if(a[j] == i) ok = 0;
            if(ok)
            {
                a[cur] = i;
                print(n, a, cur + 1);
            }
        }
}

int main()
{
    int a[N], n;
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
            a[i]=i*i+2;
        do{
            for(int i=0;i<n;++i)
                printf("%d ",a[i]);
            printf("\n");
        }while(next_permutation(a,a+n));
        //print(n, a, 0);
        printf("\n");
    }
    return 0;
}
