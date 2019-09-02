/*
https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6

题目描述
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1到n中1出现的次数）。
*/

#include <cmath>
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
  public:
    map<int, int> mem;
    int NumberOf1Between1AndN_Solution(int n) {
        if (n < 10)
            return n > 0 ? 1 : 0;
        if (mem.count(n) > 0)
            return mem[n];

        int expo = log10(n);
        int base = pow(10, expo);
        int ans = 0;

        int digit = n / base;
        if (digit > 1)
            ans += base;
        if (digit == 1)
            ans += n % base + 1;
        ans += digit * NumberOf1Between1AndN_Solution(base - 1);
        ans += NumberOf1Between1AndN_Solution(n % base);

        mem[n] = ans;
        return ans;
    }
};

// int main() {
//     int x = 13;
//     cout << int(log10(x)) << endl;
//     cout << Solution().NumberOf1Between1AndN_Solution(x);
//     return 0;
// }
