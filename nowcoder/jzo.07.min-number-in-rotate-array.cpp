/*
https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba
题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

#include <vector>
using namespace std;

class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if (rotateArray.size() == 0){
            return 0;
        }
        int le = 0, ri = rotateArray.size() - 1;
        int mid;
        while (le < ri)
        {
            mid = (le + ri) >> 1;
            if (rotateArray[mid] > rotateArray[ri])
            {
                le = mid + 1;
            }
            else if (rotateArray[mid] < rotateArray[ri])
            {
                ri = mid;
            }
            else
            {
                ri -= 1;
            }
        }
        return rotateArray[le];
    }
};
