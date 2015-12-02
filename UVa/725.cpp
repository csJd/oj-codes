#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    char s[20];
    int n, ok, abcde, fghij, cnt,cas=-1;
    while(~scanf("%d", &n),n)
    {
        if(++cas) printf("\n");
        cnt = 0;
        for(fghij = 1234;; ++fghij)
        {
            ok = 1;
            abcde = fghij * n;
            if(abcde > 98765) break;
            sprintf(s, "%05d%05d", abcde, fghij);
            sort(s, s + 10);
            for(int i = 0; i < 10; ++i)
                if(s[i] != '0' + i) ok = 0;
            if(ok)
            {
                ++cnt;
                printf("%05d / %05d = %d\n", abcde, fghij, n);
            }
        }
        if(cnt == 0) printf("There are no solutions for %d.\n", n);
    }
    return 0;
}
