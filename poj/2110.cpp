#include<cstdio>
#include<cmath>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = { -1, 1, 0, 0};
const int N = 10;
char mat[N][N];
bool ans;
int t, sx, sy, ex, ey;

void dfs(int r, int c, int lt)
{
    if(mat[r][c] == 'D' && lt == 0||ans)  //�����������Ѿ���������
    {
        ans = true;
        return;
    }
    char tc=mat[r][c];  //����ԭ���Ŀ���ֵ ��'D'��'.'�������
    mat[r][c] = 'X';
    int rt = lt - abs(ex - r) - abs(ey - c);  //��ֱ�ߵ����յ���õ�ʱ��
    if(rt >= 0 && rt % 2 == 0)   //��֦
    for(int i = 0; i < 4; ++i)   //4��������
    {
        int x = r + dx[i], y = c + dy[i];
        if(mat[x][y] == '.' || mat[x][y] == 'D')
            dfs(x, y, lt - 1);
    }
    mat[r][c] = tc;  //�ָ�ԭ״
}

int main()
{
    int n, m;
    while(scanf("%d%d%d", &n, &m, &t), n)
    {
        for(int i = 1; i <= n; ++i)
            scanf("%s", mat[i] + 1);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
            {
                if(mat[i][j] == 'S') sx = i, sy = j;
                if(mat[i][j] == 'D') ex = i, ey = j;
            }

        ans = false;
        dfs(sx, sy, t);
        printf(ans ? "YES\n" : "NO\n");
    }
    return 0;
}
