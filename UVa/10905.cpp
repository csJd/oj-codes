#include <bits/stdc++.h>
using namespace std;
string ss[55];
bool cmp(string a, string b)
{
    return a+b > b+a;
}
int main()
{
    int n;
    while(cin >> n)
    {
        if(!n) break;
        for(int i = 0; i < n; ++i)
            cin >> ss[i];
        sort(ss, ss + n, cmp);
        for(int i = 0; i < n; ++i)
            cout << ss[i];
        puts("");
    }
    return 0;
}
//Last modified :  2015-08-17 08:18 CST

