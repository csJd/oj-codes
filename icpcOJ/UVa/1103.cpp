//#define LOCAL
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

const int maxl = 200 + 5;
char bin[256][5], s[maxl];
const int dr[] = { 1, 0, -1, 0 };
const int dc[] = { 0, 1, 0, -1 };
int picture[maxl][maxl], color[maxl][maxl], w, h;

vector<set<int> > neighbor;

void decode(int row, int col, char c)
{
    for(int i = 0; i < 4; ++i)
        picture[row][col + i] = bin[c][i] - '0';
}

bool inside(int row, int col)
{
    return row>=0 && row<h && col>=0 && col<w;
}

void DFS(int row, int col, int c)
{
    color[row][col] = c;
    for(int i = 0; i < 4; ++i)
    {
        int row2 = row + dr[i];
        int col2 = col + dc[i];
        if(inside(row2, col2) && picture[row][col] == picture[row2][col2] && color[row2][col2] == 0)
            DFS(row2, col2, c);
    }
}

void check_neighbor(int row, int col)
{
    for(int i = 0; i < 4; ++i)
    {
        int row2 = row + dr[i];
        int col2 = col + dc[i];
        if(row2>=0 && row2<h && col2>=0 && col2<w && picture[row2][col2] == 0 && color[row2][col2] != 1)//Ñ°ÕÒ"¶´"
            neighbor[color[row][col]].insert(color[row2][col2]);
    }
}

const char* code = "WAKJSD";

char recgonize(int c)
{
    int a = neighbor[c].size();
    return code[a];
}

int main(void)
{
    #ifdef LOCAL
        freopen("1103in.txt", "r", stdin);
    #endif

    strcpy(bin['0'], "0000");
    strcpy(bin['1'], "0001");
    strcpy(bin['2'], "0010");
    strcpy(bin['3'], "0011");
    strcpy(bin['4'], "0100");
    strcpy(bin['5'], "0101");
    strcpy(bin['6'], "0110");
    strcpy(bin['7'], "0111");
    strcpy(bin['8'], "1000");
    strcpy(bin['9'], "1001");
    strcpy(bin['a'], "1010");
    strcpy(bin['b'], "1011");
    strcpy(bin['c'], "1100");
    strcpy(bin['d'], "1101");
    strcpy(bin['e'], "1110");
    strcpy(bin['f'], "1111");

    int kase = 0;
    while(scanf("%d%d", &h, &w) == 2 && h)
    {
        memset(picture, 0, sizeof(picture));
        for(int i = 0; i < h; ++i)
        {
            scanf("%s", s);
            for(int j = 0; j < w; ++j)
                decode(i+1, j*4+1, s[j]);
        }

        h += 2;
        w = w * 4 + 2;

        int cnt = 0;
        vector<int> cc;
        memset(color, 0, sizeof(color));
        for(int i = 0; i < h; ++i)
            for(int j = 0; j < w; ++j)
                if(!color[i][j])
                {
                    DFS(i, j, ++cnt);
                    if(picture[i][j] == 1)    cc.push_back(cnt);
                }

        neighbor.clear();
        neighbor.resize(cnt + 1);
        for(int i = 0; i < h; ++i)
            for(int j = 0; j < w; ++j)
                if(picture[i][j] == 1)
                    check_neighbor(i, j);

        vector<char> ans;
        for(int i = 0; i < cc.size(); ++i)
            ans.push_back(recgonize(cc[i]));
        sort(ans.begin(), ans.end());

        printf("Case %d: ", ++kase);
        for(int i = 0; i < ans.size(); ++i)    printf("%c", ans[i]);
        printf("\n");
    }

    return 0;
}
