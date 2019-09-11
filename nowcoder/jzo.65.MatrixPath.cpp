/*
https://www.nowcoder.com/practice/c61c6999eecb4b8f88a98f66b273a3cc

题目描述
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步
可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
例如 [a b c e; s f c s; a d e e]
矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字
符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/

#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

class Solution {
  public:
    bool dfs(int i, int j, int &rows, int &cols, char *matrix, char *s) {
        if (!s[0]) {
            return true;
        }
        bool flag = false;
        char tmp = matrix[i * cols + j];
        matrix[i * cols + j] = 0;
        for (int d = 0; d < 4; ++d) {
            int r = i + dx[d];
            int c = j + dy[d];
            if (r >= 0 && r < rows && c >= 0 && c < cols &&
                matrix[r * cols + c] == s[0]) {
                flag = flag || dfs(r, c, rows, cols, matrix, s + 1);
            }
        }
        matrix[i * cols + j] = tmp;
        return flag;
    }

    bool hasPath(char *matrix, int rows, int cols, char *str) {
        if (matrix == nullptr || !rows || !cols) {
            return false;
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i * cols + j] == str[0]) {
                    if (dfs(i, j, rows, cols, matrix, str + 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

// int main() {
//     char mat[] = "abcesfcsadee";
//     char s[] = "bcced";
//     cout << Solution().hasPath(mat, 3, 4, s);
//     return 0;
// }
