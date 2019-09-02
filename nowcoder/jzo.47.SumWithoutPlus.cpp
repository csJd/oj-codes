/*
https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1

题目描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
*/

#include <iostream>
using namespace std;

class Solution {
  public:
    int Sum_Solution(int n) {
        int ans = n;
        ans && (ans += Sum_Solution(n - 1));
        return ans;
    }
};

// int main() {
//     int res = Solution().Sum_Solution(5);
//     cout << res << endl;
//     return 0;
// }
