/*
https://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3

题目描述
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，
你能帮助他么？
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    void reverseString(string &s, int i, int j) {
        while (i < j) {
            swap(s[i++], s[j--]);
        }
    }
    string ReverseSentence(string str) {
        int length = str.size();
        reverseString(str, 0, length - 1);
        int le = 0, ri = 1;
        while (ri <= length) {
            if (ri == length || str[ri] == ' ') {
                reverseString(str, le, ri - 1);
                le = ri + 1;
            }
            ++ri;
        }
        return str;
    }
};

// int main() {
//     string res = Solution().ReverseSentence("I am a student.");
//     cout << res << endl;
//     return 0;
// }
