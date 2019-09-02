/*
https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c

题目描述
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
*/

#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

class Solution {
  public:
    int FirstNotRepeatingChar(string str) {
        int pos[256];
        memset(pos, -1, sizeof(pos));
        int length = str.length();
        for (int i = 0; i < length; ++i) {
            if (pos[str[i]] == -1)
                pos[str[i]] = i;
            else if (pos[str[i]] >= 0)
                pos[str[i]] = -2;
        }

        int ans = -1;
        for (int i = 0; i < 256; ++i) {
            if (pos[i] >= 0 and (ans == -1 || pos[i] < pos[ans]))
                ans = i;
        }
        return ans >= 0 ? pos[ans] : -1;
    }
};

// int main() {
//     printf("%d\n", Solution().FirstNotRepeatingChar("hh"));
//     return 0;
// }
