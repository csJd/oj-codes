/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 *
 * https://leetcode.com/problems/maximum-gap/description/
 *
 * algorithms
 * Hard (32.25%)
 * Likes:    547
 * Dislikes: 136
 * Total Accepted:    73.5K
 * Total Submissions: 222.3K
 * Testcase Example:  '[3,6,9,1]'
 *
 * Given an unsorted array, find the maximum difference between the successive
 * elements in its sorted form.
 *
 * Return 0 if the array contains less than 2 elements.
 *
 * Example 1:
 *
 *
 * Input: [3,6,9,1]
 * Output: 3
 * Explanation: The sorted form of the array is [1,3,6,9], either
 * (3,6) or (6,9) has the maximum difference 3.
 *
 * Example 2:
 *
 *
 * Input: [10]
 * Output: 0
 * Explanation: The array contains less than 2 elements, therefore return 0.
 *
 * Note:
 *
 *
 * You may assume all elements in the array are non-negative integers and fit
 * in the 32-bit signed integer range.
 * Try to solve it in linear time/space.
 *
 *
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    void radix_sort(vector<int> &nums)
    {
        int length = nums.size();
        if (length < 2)
            return;
        int maxv = *max_element(nums.begin(), nums.end());
        vector<int> aux(length);

        int base = 1; // 1, 10, 100, ...
        int radix = 10;

        // for lower to higher
        while (maxv / base > 0)
        {
            // record the count of numbers whose value <= i in current digit
            vector<int> cnt(radix, 0);
            for (int x : nums)
                ++cnt[(x / base) % radix];
            for (int i = 1; i < radix; ++i)
                cnt[i] += cnt[i - 1];

            // nums are sorted according to the value in current digit
            for (int i = length - 1; i >= 0; --i)
                aux[--cnt[(nums[i] / base) % radix]] = nums[i];
            nums.assign(aux.begin(), aux.end());
            base *= radix;
        }
    }

    int maximumGap(vector<int> &nums)
    {
        int length = nums.size();
        if (length < 2)
            return 0;
        radix_sort(nums);
        int maxGap = 0;
        for (int i = 0; i < length - 1; ++i)
            maxGap = max(nums[i + 1] - nums[i], maxGap);

        return maxGap;
    }
};

// int main()
// {
//     Solution solu;
//     vector<int> nums = {1, 8, 3, 6};
//     cout << solu.maximumGap(nums) << endl;
//     return 0;
// }
