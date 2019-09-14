/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 *
 * https://leetcode.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (41.07%)
 * Likes:    936
 * Dislikes: 1434
 * Total Accepted:    256.6K
 * Total Submissions: 616.4K
 * Testcase Example:  '[1,2,3,1]'
 *
 * A peak element is an element that is greater than its neighbors.
 *
 * Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element
 * and return its index.
 *
 * The array may contain multiple peaks, in that case return the index to any
 * one of the peaks is fine.
 *
 * You may imagine that nums[-1] = nums[n] = -∞.
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index
 * number 2.
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 1 or 5
 * Explanation: Your function can return either index number 1 where the peak
 * element is 2,
 * or index number 5 where the peak element is 6.
 *
 *
 * Note:
 *
 * Your solution should be in logarithmic complexity.
 *
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int length = nums.size();
        int le = 0, ri = length - 1, mid;
        while (le < ri)
        {
            mid = (le + ri) >> 1;
            if (nums[mid] < nums[mid + 1])
                le = mid + 1;
            else
                ri = mid;
        }
        return le;
    }

    int findPeakElementBad(vector<int> &nums)
    {
        int length = nums.size();
        if (length == 1 || nums[0] > nums[1])
        {
            return 0;
        }
        else if (nums[length - 1] > nums[length - 2])
        {
            return length - 1;
        }

        int le = 1, ri = nums.size() - 2;
        while (le <= ri)
        {
            int mid = (le + ri) >> 1;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            if (nums[ri] > nums[ri - 1] && nums[ri] > nums[ri + 1])
            {
                return ri;
            }

            // there must exist peak in [mid+1, ri]
            if (nums[mid] < nums[mid + 1] && nums[ri] - nums[mid] < ri - mid)
            {
                le = mid + 1;
            }
            // there must exist peak in [le, mid-1]
            else if (nums[mid] < nums[mid - 1] && nums[le] - nums[mid] < mid - le)
            {
                ri = mid - 1;
            }
            // cannot determine
            else
            {
                ri -= 1;
            }
        }
        return 0;
    }
};

// int main()
// {
//     vector<int> nums = {1, 2, 3, 1};
//     Solution solu;
//     cout << solu.findPeakElement(nums);
//     return 0;
// }
