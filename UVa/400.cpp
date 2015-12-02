#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;
const int N = 105, M = 60;

int main()
{
    string s[N];
    int n, l, w;
    while(cin >> n)
    {
        l = 0;
        for(int i = 0; i < n; ++i)
        {
            cin >> s[i];
            if(s[i].length() > l) l = s[i].length();
        }
        int c = (M - l ) / (l + 2) + 1, r = (n - 1) / c + 1;
        sort(s, s + n);
        for(int i = 0; i < M; ++i) putchar('-');
        puts("");
        for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
            {
                if(j * r + i < n)
                {
                    w = (j == c - 1 ? l : l + 2);
                    cout << left << setw(w) << s[j * r + i];
                }
            }
            cout << endl;
        }
    }
    return 0;
}
