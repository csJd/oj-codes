/*
https://www.nowcoder.com/practice/f78a359491e64a50bce2d89cff857eb6

题目描述
每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。HF作为牛客的资深元老,自然也准备了一些小游戏。
其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。每次喊到m-1的那
个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,继续0...m-1报数....这
样下去....直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。请你试着想下,哪
个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
如果没有小朋友，请返回-1

约瑟夫环问题 https://oi-wiki.org/misc/josephus/
*/

#include <iostream>
using namespace std;

class Solution {
  public:
    int LastRemaining_Solution(int n, int m) {
        if (n == 0) {
            return -1;
        }
        return josephus(n, m);
    }

    // 从 0 开始数 k 个，让第 k-1 个人出局后剩下 n-1 个人，计算出在 n - 1
    // 个人中选的答案后， 再加一个相对位移 k 得到真正的答案。 J(n, k) = (J(n-1,
    // k) + k) % n
    int josephus(int n, int k) {
        int res = 0;
        for (int i = 1; i <= n; ++i)
            res = (res + k) % i; // res = J(i, k) = (J(i-1, k) + k) % n
        return res;
    }
};

// int main() {
//     int res = Solution().LastRemaining_Solution(3, 2);
//     cout << res << endl;
//     return 0;
// }
