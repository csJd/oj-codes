#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int a[N], n;

bool havel()
{
    for(int i = n - 1; i >= 0; --i)
    {
        sort(a, a + i + 1);
        if(a[i] > i) return false;
        for(int j = i - a[i]; j < i; ++j)
            if((--a[j]) < 0) return false;
    }
    return true;
}

int main()
{
    while(scanf("%d", &n), n)
    {
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        puts(havel() ? "Possible" : "Not possible");
    }
    return 0;
}
