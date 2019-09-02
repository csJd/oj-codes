/*
https://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b

题目描述
把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，
因为它包含质因子7。习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int GetUglyNumber_Solution(int index) {
        if (index < 7)
            return index;

        vector<int> nums;
        nums.push_back(1);
        int p2 = 0, p3 = 0, p5 = 0;
        while (nums.size() < index) {
            int cur = min(nums[p2] * 2, min(nums[p3] * 3, nums[p5] * 5));
            if (cur == nums[p2] * 2)
                ++p2;
            if (cur == nums[p3] * 3)
                ++p3;
            if (cur == nums[p5] * 5)
                ++p5;
            nums.push_back(cur);
        }
        return nums.back();
    }
};

// int main() {
//     cout << Solution().GetUglyNumber_Solution(8) << endl;
//     return 0;
// }
