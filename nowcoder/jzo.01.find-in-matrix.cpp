/*
https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e

题目描述
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

#include <vector>
using namespace std;

class Solution
{
public:
    bool Find(int target, vector<vector<int>> array)
    {
        int n = 0, m = 0;
        if (array.empty())
            return false;
        else
            n = array.size();
        if (array[0].empty())
            return false;
        else
            m = array[0].size();

        // search from left-down
        int i = n - 1, j = 0;
        while (i > -1 && j < m)
        {
            if (target == array[i][j])
                return true;
            if (target < array[i][j])
                i -= 1;
            else
                j += 1;
        }
        return false;
    }
};
