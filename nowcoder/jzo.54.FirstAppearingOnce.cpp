/*
https://www.nowcoder.com/practice/00de97733b8e4f97a3fb5c680ee10720

题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符
是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。

输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。

*/

#include <cstdio>
#include <cstring>
using namespace std;

const int SIZE = 256;

class Solution {
  public:
    int pos[SIZE];
    int cur;

    Solution() {
        memset(pos, -1, sizeof(pos));
        cur = 0;
    }

    // Insert one char from stringstream
    void Insert(char ch) {
        if (pos[ch] == -1) {
            pos[ch] = cur;
        } else {
            pos[ch] = -2;
        }
        cur += 1;
    }

    // return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        int firstPos = cur;
        char firstChar = '#';
        for (int i = 0; i < SIZE; ++i) {
            if (pos[i] >= 0 && pos[i] < firstPos) {
                firstChar = i;
                firstPos = pos[i];
            }
        }
        return firstChar;
    }
};

// int main() {
//     char s[] = "google";
//     Solution solu;
//     for (char c : s) {
//         solu.Insert(c);
//         printf("%c", solu.FirstAppearingOnce());
//     }
//     puts("");

//     return 0;
// }
