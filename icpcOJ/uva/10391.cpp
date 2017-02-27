#include <bits/stdc++.h>
using namespace std;
string a, b;
set<string> s;
set<string>::iterator i;

int main()
{
    int l;
    while(cin >> a) s.insert(a);
    for(i = s.begin(); i != s.end(); ++i)
    {
        l = i->length();
        for(int j = 1; j < l - 1; ++j)
        {
            a = i->substr(0, j);
            b = i->substr(j);
            if(s.count(a) && s.count(b))
            {
                cout << (*i) << endl;
                break;
            }
        }
    }
    return 0;
}
