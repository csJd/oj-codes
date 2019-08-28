/*
https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337
题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/

// struct ListNode {
//     int val;
//     struct ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
  public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
        ListNode *pseudoHead = new ListNode(0);
        ListNode *p = pseudoHead;
        while (pHead1 and pHead2) {
            if (pHead1->val < pHead2->val) {
                p->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                p->next = pHead2;
                pHead2 = pHead2->next;
            }
            p = p->next;
        }
        if (pHead1) {
            p->next = pHead1;
        }
        if (pHead2) {
            p->next = pHead2;
        }
        ListNode *head = pseudoHead->next;
        delete pseudoHead;
        return head;
    }
};
