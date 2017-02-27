#include<cstdio>
using namespace std;
int main()
{
    unsigned n, l, u, m, t;
    while(~scanf("%u%u%u", &n, &l, &u))
    {
        m = 0;
        for(int i = 31; i >= 0; --i)
        {
            t = m | (1u << i); //t为m在该位置1后的值
            if(t <= u && !(n & 1u << i)) m = t;  //n的i位为0 m该位置为1后不会超过u
            if(m < l && (l & 1u << i)) m = t;  //m<l l的该位又为1时 该位必须置1
        }
        printf("%u\n", m);
    }
    return 0;
}
