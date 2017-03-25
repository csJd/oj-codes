#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

struct matrix
{
    int x, y, a, b, h;
} mat[N];

bool intersect(matrix &i, matrix &j) //ÅĞ¶ÏÊÇ·ñÏà½»
{
    if(i.x + i.a <= j.x || i.x >= j.x + j.a) return false;
    if(i.y + i.b <= j.y || i.y >= j.y + j.b) return false;
    return true;
}

int main()
{
    int n, m, c, h;
    while(~scanf("%d%d%d", &n, &m, &c))
    {
        int ans = 0;
        for(int i = 0; i < c; ++i)
        {
            scanf("%d%d%d%d%d", &mat[i].a, &mat[i].b, &h, &mat[i].x, &mat[i].y);
            mat[i].h = 0;
            for(int j = 0; j < i; ++j)
                if(intersect(mat[i], mat[j]))
                    mat[i].h = max(mat[i].h, mat[j].h);
            mat[i].h += h;
            ans = max(ans, mat[i].h);
        }
        printf("%d\n", ans);
    }

    return 0;
}
//Last modified :   2015-07-31 08:55

