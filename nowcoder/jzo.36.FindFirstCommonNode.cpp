/*
https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46

题目描述
输入两个链表，找出它们的第一个公共结点，不存在返回 nullptr。
*/

// struct ListNode {
//     int val;
//     struct ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
  public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
        if (pHead1 == nullptr or pHead2 == nullptr)
            return nullptr;

        ListNode *p1 = pHead1, *p2 = pHead2;
        while (p1 != p2) {
            if (p1 == nullptr) {
                p1 = pHead2;
                p2 = p2->next;
            } else if (p2 == nullptr) {
                p2 = pHead1;
                p1 = p1->next;
            } else {
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        return p1;
    }
};
