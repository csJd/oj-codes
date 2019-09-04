/*
https://www.nowcoder.com/practice/6f8c901d091949a5837e24bb82a731f2

题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都
表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

*/

#include <cstring>
#include <iostream>
#include <regex>
using namespace std;

class Solution {
  public:
    /*
        [\\+\\-]?            -> 正或负符号出现与否
        \\d*                 -> 整数部分是否出现，如-.34 或 +3.34均符合
        (\\.\\d+)?           -> 如果出现小数点，那么小数点后面必须有数字；
                                否则一起不出现
        ([eE][\\+\\-]?\\d+)? -> 如果存在指数部分，那么e或E肯定出现，+或-可以不出现，
                                紧接着必须跟着整数；或者整个部分都不出现
    */
    bool isNumeric(char *string) {
        regex re("[\\+\\-]?\\d*(\\.\\d+)?([eE][\\+\\-]?\\d+)?");
        return regex_match(string, re);
    }
};

// int main() {
//     cout << Solution().isNumeric("+100") << endl;
//     cout << Solution().isNumeric("-1e-16") << endl;
//     cout << Solution().isNumeric("1.2.3") << endl;
//     return 0;
// }
