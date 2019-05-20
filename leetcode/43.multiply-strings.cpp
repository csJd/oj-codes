/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (30.40%)
 * Likes:    963
 * Dislikes: 442
 * Total Accepted:    198.8K
 * Total Submissions: 650.1K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 *
 * Example 1:
 *
 *
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 *
 * Example 2:
 *
 *
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 *
 *
 * Note:
 *
 *
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 *
 *
 */
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string add(string num1, string num2)
    {
        int len1 = num1.length(), len2 = num2.length();
        int pos = -1;
        string result = "";
        int carry = 0;
        int d1, d2, digit;
        while (pos + len1 >= 0 || pos + len2 >= 0 || carry > 0)
        {
            d1 = d2 = 0;
            if (pos + len1 >= 0)
            {
                d1 = num1[len1 + pos] - '0';
            }
            if (pos + len2 >= 0)
            {
                d2 = num2[len2 + pos] - '0';
            }
            digit = (d1 + d2 + carry) % 10;
            carry = (d1 + d2 + carry) / 10;
            result += '0' + digit;
            pos -= 1;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return string("0");
        }
        int len1 = num1.length(), len2 = num2.length();
        string result = "0";
        string append = "";
        for (int i = len2 - 1; i >= 0; --i)
        {
            if (len1 == 1)
            {
                result = add(result, to_string((num2[i] - '0') * (num1[0] - '0')) + append);
            }
            else
            {
                result = add(result, multiply(string(1, num2[i]), num1) + append);
            }
            append += '0';
        }
        return result;
    }
};

// int main(int argc, char const *argv[])
// {
//     Solution solu = Solution();
//     cout << solu.add("0", "1") << endl;
//     cout << solu.multiply("123", "456") << endl;
//     return 0;
// }
