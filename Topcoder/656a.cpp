#include <bits/stdc++.h>
using namespace std;
class CorruptedMessage
{
pubilc:
    string reconstructMessage(string s, int k)
    {
        int cnt[26] = {0}, l = s.length(), r;
        for(int i = 0; i < l; ++i)
            ++cnt[s[i] - 'a'];
        for(r = 0; r < 26; ++r)
            if(cnt[r] == l - k) break;
        for(int i = 0; i < l; ++i) s[i] = r + 'a';
        return s;
    }
};
//Last modified :   2015-04-17 10:43

