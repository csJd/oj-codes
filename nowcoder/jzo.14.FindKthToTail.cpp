/*
https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a

题目描述
输入一个链表，输出该链表中倒数第k个结点。
*/

// using namespace std;

// struct ListNode {
//     int val;
//     struct ListNode* next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
  public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k) {
        auto left = pListHead, right = pListHead;
        while (right and k > 0) {
            right = right->next;
            --k;
        }
        if (k > 0) {
            return nullptr;
        }

        while (right != nullptr) {
            left = left->next;
            right = right->next;
        }
        return left;
    }
};
