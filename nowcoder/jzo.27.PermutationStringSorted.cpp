/*
https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7

题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<string> permutationSorted(string str) {
        int length = str.length();
        if (length == 1) {
            return {str};
        }

        vector<string> res;
        for (int i = 0; i < length; i += 1) {
            if (i != 0 and str[i] == str[0])
                continue;
            swap(str[i], str[0]);
            for (string s : Permutation(str.substr(1))) {
                res.push_back(str[0] + s);
            }
            swap(str[i], str[0]);
        }
        return res;
    }

    vector<string> Permutation(string str) {
        sort(str.begin(), str.end());
        return permutationSorted(str);
    }
};

// int main() {
//     for (string s : Solution().Permutation("cba"))
//         cout << s << endl;
//     for (string s : Solution().Permutation("aaa"))
//         cout << s << endl;
//     return 0;
// }
