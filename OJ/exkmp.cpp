#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10005;
char p[N];
int exp[N], lp;

void exkmp()
{
    int k = exp[0] = 0;
    //exp[0...i-1]均已经求出  0 < k < i && k + exp[k]最大
    for(int i = 1; i < lp; ++i) 
    {
        int j = exp[i - k];  
        //p[k, k + exp[k]) == p[0, exp[k]) => p[i, k + exp[k]) == p[i - k, exp[k])
        //当i + exp[i - k] < k + exp[k]时  显然exp[i] = exp[i - k] 否则 要继续从k + exp[k] - i匹配
        if(i + j >= k + exp[k])
        {
            j = max(0, k + exp[k] - i);
            while(j < lp && p[i + j] == p[j]) ++j;
        }
        exp[i] = j;
        if(i + j > k + exp[k]) k = i;
    }
    exp[0] = lp;
}

int main()
{
    while(~scanf("%s", p))
    {
        lp = strlen(p);
        exkmp();
        for(int i = 0; i < lp; ++i)
            printf("%d ",  exp[i]);
        puts("");
    }
    return 0;
}
//Last modified :  2015-09-29 09:58 CST

