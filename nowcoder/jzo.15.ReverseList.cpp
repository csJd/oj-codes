/*
https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca

题目描述
输入一个链表，反转链表后，输出新链表的表头。
*/

// #include <iostream>
// #include <vector>
// using namespace std;

// struct ListNode
// {
//     int val;
//     struct ListNode *next;
//     ListNode(int x) : val(x), next(nullptr){}
// };

class Solution {
  public:
    ListNode *ReverseList(ListNode *pHead) {
        ListNode *pseudoHead = new ListNode(0);
        ListNode *tail;
        pseudoHead->next = pHead;

        tail = pHead;
        while (tail && tail->next) {
            // insert tail->next to head
            ListNode *p = tail->next;
            tail->next = p->next;
            p->next = pseudoHead->next;
            pseudoHead->next = p;
        }
        pHead = pseudoHead->next;
        delete pseudoHead;

        return pHead;
    }
};

// void printList(ListNode *head)
// {
//     while (head != nullptr)
//     {
//         cout << head->val << ' ';
//         head = head->next;
//     }
//     cout << endl;
// }

// ListNode *listBuilder(vector<int> &arr)
// {

//     ListNode *pseudoHead = new ListNode(0);
//     ListNode *tail = pseudoHead;
//     for (int x : arr)
//     {
//         tail->next = new ListNode(x);
//         tail = tail->next;
//     }
//     return pseudoHead->next;
// }

// int main()
// {
//     vector<int> arr = {1, 2, 3, 4, 5};
//     ListNode *head = listBuilder(arr);

//     printList(head);
//     Solution solu;
//     head = solu.ReverseList(head);
//     printList(head);

//     return 0;
// }
