#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int a[N], n;

void toTrue(int i)
{
    int m = i, j;
    for(j = i + 1; j <= n; ++j)
        if(a[j] > a[m]) m = j;
    if(m != i)
    {
        if(m != n)
        {
            j = n;
            printf("%d ", m);
            while(m < j) swap(a[m++], a[j--]);
        }
        j = n;
        printf("%d ", i);
        while(i < j) swap(a[i++], a[j--]);
    }
}

int main()
{
    string s;
    int i, j;
    while(getline(cin, s))
    {
        n = 0;
        stringstream in(s);
        while(in >> a[++n]);
        for(i = 1; i < n - 1; ++i) printf("%d ", a[i]);
        printf("%d\n", a[--n]);
        i = 1, j = n;
        while(i < j) swap(a[i++], a[j--]);
        for(i = 1; i <= n; ++i) toTrue(i);
        puts("0");
    }
    return 0;
}

/*
1 3 2 5 4 6 7
4 3 4 6 5 0
7 6 4 5 3 1 2
1 4 3 4 5 6 0
*/
