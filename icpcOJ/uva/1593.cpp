#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 200;
string s[N][M], line;
int cw[M], cn[N];

int main()
{
    int r = 0, c = 0;
    while(getline(cin, line))
    {
        stringstream ss(line);
        while(ss >> s[r][c])
        {
            if(s[r][c].length() > cw[c])
                cw[c] = s[r][c].length();
            ++c;
        }
        cn[r++] = c;
        c = 0;
    }

    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < cn[i] - 1; ++j)
            cout << left << setw(cw[j] + 1) << s[i][j];
        cout << s[i][cn[i] - 1] << endl;
    }
    return 0;
}
