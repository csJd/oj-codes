#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b, t;
    while(~scanf("%d", &n))
    {
        deque<int> qa, qb;
        scanf("%d", &a);
        while(a--)
        {
            scanf("%d", &t);
            qa.push_back(t);
        }

        scanf("%d", &b);
        while(b--)
        {
            scanf("%d", &t);
            qb.push_back(t);
        }
        set<string> vis;
        int cnt =  0;
        deque<int>::iterator it;
        while((!qa.empty()) && (!qb.empty()))
        {
            string s = "";
            for(it = qa.begin(); it != qa.end(); ++it)
                s += ('a' + *it);
            if(vis.count(s)) break;
            else vis.insert(s);

            a = qa.front(), b = qb.front();
            qa.pop_front(), qb.pop_front();
            if(a > b)
                qa.push_back(b), qa.push_back(a);
            else
                qb.push_back(a), qb.push_back(b);
            ++cnt;
        }

        if(qa.empty())
            printf("%d %d\n", cnt, 2);
        else if(qb.empty())
            printf("%d %d\n", cnt, 1);
        else puts("-1");
    }
    return 0;
}
//Last modified :   2015-05-23 01:10

