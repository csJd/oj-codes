#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
bool lock;
deque<int> qr;//执行队列
queue<int> qb;//等待队列
vector<string> prg[N];
string s;
int t[N], p[N], var[26], lim;

void run(int i)
{
    int rt = lim, v;
    string cur;
    while(rt > 0)
    {
        cur = prg[i][p[i]];
        if(cur[2] == '=')  // 赋值
        {
            rt -= t[0];
            v = cur[4] - '0';
            if(cur.size() == 6) v = v * 10 + cur[5] - '0';
            var[cur[0] - 'a'] = v;
        }
        else if(cur[2] == 'i')   //print
        {
            rt -= t[1];
            printf("%d: %d\n", i, var[cur[6] - 'a']);
        }
        else if(cur[2] == 'c')   //lock
        {
            rt -= t[2];
            if(lock)
            {
                qb.push(i);
                return;
            }
            else lock = true;
        }
        else if(cur[2] == 'l')  //unlock
        {
            lock = false;
            rt -= t[3];
            if(!qb.empty())
            {
                v = qb.front();
                qb.pop();
                qr.push_front(v);
            }
        }
        else return;  //end
        ++p[i];
    }
    qr.push_back(i);
}

int main()
{
    int cas, n;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d", &n);
        for(int i = 0; i < 5; ++i)
            scanf("%d", &t[i]);
        scanf("%d", &lim);

        for(int i = 1; i <= n; ++i)
        {
            prg[i].clear();
            while(getline(cin, s))
            {
                if(s == "") continue;
                prg[i].push_back(s);
                if(prg[i].back() == "end") break;
            }
            qr.push_back(i);
        }

        memset(p, 0, sizeof(p));
        memset(var, 0, sizeof(var));
        while(!qr.empty())
        {
            int cur = qr.front();
            qr.pop_front();
            run(cur);
        }
        if(cas) puts("");
    }
    return 0;
}
