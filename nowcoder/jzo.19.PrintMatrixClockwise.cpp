/*
https://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a
题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4
X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

// #include <iostream>
// #include <vector>
// using namespace std;

class Solution {
  public:
    bool valid(int r, int c, vector<vector<bool>> &vis) {
        int n = vis.size();
        int m = vis[0].size();
        return not(r < 0 or r >= n or c < 0 or c >= m or vis[r][c]);
    }

    vector<int> printMatrix(vector<vector<int>> matrix) {
        vector<int> res;
        if (matrix.empty())
            return res;

        int n = matrix.size();
        int m = matrix[0].size();
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int d = 0; // direction
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int i = 0, j = 0;
        while (valid(i, j, vis)) {
            res.push_back(matrix[i][j]);
            vis[i][j] = true;
            if (not(valid(i + dx[d], j + dy[d], vis)))
                d = (d + 1) % 4;
            i += dx[d];
            j += dy[d];
        }
        return res;
    }
};

// int main() {
//     vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     vector<int> res = Solution().printMatrix(mat);
//     for (int x : res) {
//         cout << x << ' ';
//     }
//     cout << endl;
//     return 0;
// }
