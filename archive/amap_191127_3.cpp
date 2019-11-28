// 给定两个只带数字的字符串S和T，请计算两个字符串中公共的最大整数的长度，例如S:000132456,T:45670000132,
// 返回值456,3；（涉及算法部分代码，请手动编写，不能用基础库）

#include <iostream>
#include <string>
using namespace std;

// dp solution
pair<string, int> solve(string s, string t) {
    int ls = s.size();
    int lt = t.size();
    int dp[ls + 1][lt + 1] = {0}; // dp[i][j] 为 s[:i] 和 t[:j] 最长公共后缀长度
    // dp[i][j] = dp[i-1][j-1] + 1 if s[i-1] == t[j-1] else 0

    string ans = "";
    int l = 0;
    for (int i = 0; i < ls; ++i) {
        for (int j = 0; j < lt; ++j) {
            if (s[i] == t[j]) {
                int l = dp[i][j] + 1;
                dp[i + 1][j + 1] = l;

                string suf = s.substr(i - l + 1, l);
                if (suf[0] == '0') { // remove prefix 0
                    int start = 0;
                    while (start < suf.size() && suf[start] == '0')
                        ++start;
                    suf = suf.substr(start);
                    if (suf.empty())
                        suf = "0";
                }

                if (suf > ans) {
                    ans = suf;
                }
            }
        }
    }
    return make_pair(ans, ans.size());
}

// brute force solution
pair<string, int> bf_solve(string s, string t) {
    int ls = s.size();
    int lt = t.size();

    string ans = "";

    for (int i = 0; i < ls; ++i) {
        for (int j = 0; j < lt; ++j) {
            if (s[i] == '0' or s[i] != t[j]) {
                continue;
            }
            int l = 1;

            while (i + l < ls && j + l < lt && s[i + l] == t[j + l]) {
                ++l;
            }

            string cur = s.substr(i, l);

            if (cur.size() > ans.size() ||
                (cur.size() == ans.size()) and cur > ans) {
                ans = cur;
            }
        }
    }
    return make_pair(ans, ans.size());
}

int main() {
    auto p = solve("000132456", "45670000132");
    cout << p.first << "," << p.second << endl;
    p = solve("0", "0");
    cout << p.first << "," << p.second << endl;
}
