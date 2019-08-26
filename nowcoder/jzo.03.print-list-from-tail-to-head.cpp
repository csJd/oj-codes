/*
题目描述
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*/

# include <vector>
# include <algorithm>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};


class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        while (head != NULL){
            result.push_back(head->val);
            head = head->next;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
