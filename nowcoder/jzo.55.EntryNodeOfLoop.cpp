/*
https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4

题目描述
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
*/

using namespace std;

// struct ListNode {
//     int val;
//     struct ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
  public:
    ListNode *EntryNodeOfLoop(ListNode *pHead) {
        ListNode *fast = pHead, *slow = pHead;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }

        if (!(fast && fast->next)) {
            return nullptr;
        }

        slow = pHead;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
