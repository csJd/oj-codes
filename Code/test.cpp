
#include<cstdio>
using namespace std;
int main()
{
    int i = 3;
    int k = (++i) + (++i) + (i++);
    printf("%d\n", k);
    return 0 ;
}
