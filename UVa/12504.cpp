#include <bits/stdc++.h>
using namespace std;
map<string, string> d[2];
map<string, string>::iterator it;
const int N = 105;
string s, a, b, t[N];

void print(char c, int n)
{
    sort(t, t + n), cout << c << t[0];
    for(int i = 1; i < n; ++i) cout << ',' << t[i];
    puts("");
}

int main()
{
    int cas, n, c1, c2, c3;
    cin >> cas;
    while(cas--)
    {
        d[0].clear(), d[1].clear();
        for(int i = 0; i < 2; ++i)
        {
            cin >> s;
            int j = 1, l = s.size();
            while(l > 2 && j < l)
            {
                while(s[j] != ':') a += s[j++]; ++j;
                while(s[j] != ',' && s[j] != '}') b += s[j++]; ++j;
                d[i][a] = b, a = b = "";
                //cout << a << " : " << b << endl;
            }
        }

        c1 = c2 = c3 = 0;
        for(it = d[1].begin(); it != d[1].end(); ++it)
            if(!d[0].count(it->first)) t[c1++] = it->first;
        if(c1) print('+', c1);

        for(it = d[0].begin(); it != d[0].end(); ++it)
            if(!d[1].count(it->first)) t[c2++] = it->first;
        if(c2) print('-', c2);

        for(it = d[1].begin(); it != d[1].end(); ++it)
            if(d[0].count(it->first) && d[0][it->first] != it->second) t[c3++] = it->first;
        if(c3) print('*', c3);

        if(!(c1 || c2 || c3)) puts("No changes");
        puts("");
    }
    return 0;
}
