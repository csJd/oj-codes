/*
https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba

题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/

#include <map>
using namespace std;

// struct RandomListNode {
//     int label;
//     struct RandomListNode *next, *random;
//     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
// };

class Solution {
  public:
    RandomListNode *Clone(RandomListNode *pHead) {
        map<RandomListNode *, RandomListNode *> ht;
        ht[nullptr] = nullptr;
        RandomListNode *p = pHead;

        while (p != nullptr) {
            if (ht.count(p) == 0) {
                ht[p] = new RandomListNode(p->label);
            }
            if (p->next && ht.count(p->next) == 0) {
                ht[p->next] = new RandomListNode(p->next->label);
            }
            if (p->random && ht.count(p->random) == 0) {
                ht[p->random] = new RandomListNode(p->random->label);
            }
            ht[p]->next = ht[p->next];
            ht[p]->random = ht[p->random];
            p = p->next;
        }

        return ht[pHead];
    }
};
