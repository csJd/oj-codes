/*
https://www.nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46

题目描述
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次
（包含0次）。
在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与
"aa.a"和"ab*a"均不匹配
*/

#include <cstring>
#include <iostream>
using namespace std;

class Solution {
  public:
    bool match(char *s, char *p) {
        int ls = strlen(s), lp = strlen(p);
        // dp[i][j] represents match(s[:i], p[:j])
        bool dp[ls + 1][lp + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for (int j = 1; j < lp; j += 2) {
            if (p[j] == '*' and p[j - 1] != '*') {
                dp[0][j + 1] = true;
            } else {
                break;
            }
        }

        for (int i = 0; i < ls; ++i) {
            for (int j = 0; j < lp; ++j) {
                if (s[i] == p[j] || p[j] == '.') {
                    // p[j] match s[i]
                    dp[i + 1][j + 1] = dp[i + 1][j + 1] || dp[i][j];
                } else if (p[j] == '*' && j > 0) {
                    // * match zero times
                    dp[i + 1][j + 1] = dp[i + 1][j + 1] || dp[i + 1][j - 1];

                    // * match s[i]
                    if (p[j - 1] == '.' || p[j - 1] == s[i]) {
                        dp[i + 1][j + 1] = dp[i + 1][j + 1] || dp[i][j + 1];
                    }
                }
            }
        }
        return dp[ls][lp];
    }
};

// int main() {
//     char s[] = "a";
//     char p[] = "a";
//     cout << (Solution().match(s, p) ? "true" : "false") << endl;
//     cout << (Solution().match("", "a*b*") ? "true" : "false") << endl;
//     cout << (Solution().match("ab", ".*") ? "true" : "false") << endl;
//     cout << (Solution().match("abbbb", ".b*") ? "true" : "false") << endl;
//     cout << (Solution().match("aab", "c*a*b") ? "true" : "false") << endl;
//     return 0;
// }
