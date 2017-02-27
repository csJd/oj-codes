#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 10;
int g[N][N], in[N], q[N];
vector<int> e[N];

void build() //建图
{
    memset(in, 0, sizeof(in));
    for(int k = 0; k < 9; ++k)
    {
        e[k].clear();
        int i = k / 3, j = k % 3, t; //获取程序k的左上角坐标
        for(int x = 0; x < 2; ++x)
        for(int y = 0; y < 2; ++y)
        {
            t = g[i + x][j + y];
            if(t != k) //程序k在程序t之前运行 k < t
            {
                e[k].push_back(t);
                ++in[t];
            }
        }
    }
}

bool topo()
{
    build();
    int front = 0, rear = 0, cur;
    for(int i = 0; i < 9; ++i)
        if(!in[i]) q[rear++] = i;
    while(front < rear)
    {
        cur = q[front++];
        for(int i = 0; i < e[cur].size(); ++i)
        {
            int j = e[cur][i];
            if(!(--in[j])) q[rear++] = j;
        }
    }
    return front >= 9; //front < 9 时有环
}

int main()
{
    char s[100];
    while(scanf("%s", s), s[0] != 'E')
    {
        for(int i = 0; i < 4; ++i)
            for(int j = 0; j < 4; ++j)
                scanf("%d", &g[i][j]), --g[i][j];
        scanf("%s", s);
        printf("THESE WINDOWS ARE ");
        puts(topo() ? "CLEAN" : "BROKEN");
    }
    return 0;
}
//Last modified :  2015-08-19 15:34 CST

