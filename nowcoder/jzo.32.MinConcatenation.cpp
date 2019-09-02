/*
https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993

题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(int x, int y) {
    string xs = to_string(x);
    string ys = to_string(y);
    return xs + ys < ys + xs;
}

class Solution {
  public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), cmp);
        string res = "";
        for (int num : numbers) {
            res += to_string(num);
        }
        return res;
    }
};

// int main() {
//     cout << Solution().PrintMinNumber({3, 32, 321});
//     return 0;
// }
