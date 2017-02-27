#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
char st[11][11] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char gt[30][22] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                   "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                   "eighteen", "nineteen"
                  };
int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        if(n == 0) puts("zero");
        else if(n < 20) puts(gt[n]);
        else
        {
            int a = n % 10, b = n / 10;
            if(a == 0) puts(st[b]);
            else printf("%s-%s\n", st[b], gt[a]);
        }
    }
    return 0;
}

