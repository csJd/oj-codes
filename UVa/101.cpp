#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 30;
vector<int> pile[N], t;
int n, pa, pb, ha, hb;

void find_block(int i, int &p, int &h)
{
    for(p = 0; p < n; ++p)
        for(h = 0; h < pile[p].size(); ++h)
            if(pile[p][h] == i) return;
}

void clear_above(int p, int h)
{
    for(int i = h + 1; i < pile[p].size(); ++i)
        pile[pile[p][i]].push_back(pile[p][i]);
    pile[p].resize(h + 1);
}

void pile_onto(int p, int h, int p2)
{
    for(int i = h; i < pile[p].size(); ++i)
        pile[p2].push_back(pile[p][i]);
    pile[p].resize(h);
}

int main()
{
    char s1[N], s2[N];
    int a,b;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; ++i)
            pile[i].clear(), pile[i].push_back(i);
        while(scanf("%s", s1), s1[0] != 'q')
        {
            scanf("%d%s%d", &a, s2, &b);
            find_block(a, pa, ha);
            find_block(b, pb, hb);
            if(pa == pb) continue;
            if(s2[1] == 'n') clear_above(pb, hb);
            if(s1[0] == 'm') clear_above(pa, ha);
            pile_onto(pa, ha, pb);
        }

        for(int i = 0; i < n; ++i)
        {
            printf("%d:", i);
            for(int j = 0; j < pile[i].size(); ++j)
                printf(" %d", pile[i][j]);
            puts("");
        }
    }
    return 0;
}
