#include <bits/stdc++.h>
using namespace std;
const int N = 7;
int main()
{
    int n;
    string na, t;
    string s[N] = {"A", "C", "G", "AC", "AG", "CG", "ACG"};
    while(cin >> n)
    {
        map<string, int> cnt;
        for(int i = 0; i < n; ++i)
        {
            cin >> na >> t;
            sort(t.begin(), t.end());
            ++cnt[t];
        }

        int a = cnt["A"], c = cnt["C"], g = cnt["G"];
        int ac = cnt["AC"], ag = cnt["AG"], cg = cnt["CG"];
        int acg = cnt["ACG"];

        int flag = 0;

        //所有人都有某个兴趣
        if(a + ac + ag + acg >= n) flag = 1;
        if(c + ac + cg + acg >= n) flag = 1;
        if(g + ag + cg + acg >= n) flag = 1;

        //所有人中某个兴趣没有单独出现
        if(!a && cg + acg > 1) flag = 1;
        if(!c && ag + acg > 1) flag = 1;
        if(!g && ac + acg > 1) flag = 1;

        //出现了三种兴趣
        if(!flag)
        {
            if(ac > 0 || (ag > 1 && cg > 1)) ++flag;
            if(ag > 0 || (ac > 1 && cg > 1)) ++flag;
            if(cg > 0 || (ac > 1 && ag > 1)) ++flag;
            flag = (flag + acg > 2);
        }

        t  = flag ? "Yes" : "No";
        cout << t << endl;
    }

    return 0;
}
//Last modified :   2015-07-14 20:08
/*
7
1 A
2 C
3 G
4 AC
5 AC
6 AG
7 AG

4
1 AC
2 A
3 AC
4 CG
*/


