/*
https://www.nowcoder.com/practice/6e5207314b5241fb83f2329e89fdecc8

题目描述
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 =
18。但是，它不能进入方格（35,38），因为3+5+3+8 =
19。请问该机器人能够达到多少个格子？
*/

#include <iostream>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

class Solution {
  public:
    int digitsSum(int a, int b) {
        int res = 0;
        while (a || b) {
            res += a % 10;
            res += b % 10;
            a /= 10;
            b /= 10;
        }
        return res;
    }

    void dfs(int r, int c, int &rows, int &cols, int &cnt, bool vis[]) {
        vis[r * cols + c] = true;
        cnt += 1;
        for (int d = 0; d < 4; ++d) {
            int nr = r + dx[d];
            int nc = c + dy[d];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                !vis[nr * cols + nc]) {
                dfs(nr, nc, rows, cols, cnt, vis);
            }
        }
    }

    int movingCount(int threshold, int rows, int cols) {
        if (threshold < 0) {
            return 0;
        }

        bool vis[rows * cols];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                vis[i * cols + j] = (digitsSum(i, j) > threshold);
            }
        }
        int cnt = 0;
        dfs(0, 0, rows, cols, cnt, vis);
        return cnt;
    }
};

// int main() {
//     cout << Solution().movingCount(2, 3, 3);
//     return 0;
// }
