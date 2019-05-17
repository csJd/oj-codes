# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        ret = ListNode(0)
        p = ret
        c = 0
        while l1 and l2:
            sum = l1.val + l2.val + c
            p.val = sum % 10
            p.next = ListNode(0)
            p = p.next
            c = sum // 10
            l1 = l1.next
            l2 = l2.next

        while l1:
            sum = l1.val + c
            p.val = sum % 10
            p.next = ListNode(0)
            p = p.next
            c = sum // 10
            l1 = l1.next

        while l2:
            sum = l2.val + c
            p.val = sum % 10
            p.next = ListNode(0)
            p = p.next
            c = sum // 10
            l2 = l2.next

        if c:
            p.val = c

        p = ret
        while p and p.next:
            if p.next.next is None and p.next.val == 0:
                p.next = None
            p = p.next

        return ret
        # p = ret
        # while p:
        #     print('%d -> ', p.val)
        #     if p.next.val == 0 and p.next.next == None:
        #         p.next = None
        #     p = p.next


class BetterSolution:
    def addTwoNumbers(self, l1, l2):
        carry = 0
        root = p = ListNode(0)
        while l1 or l2 or carry:
            v1 = v2 = 0
            if l1:
                v1 = l1.val
                l1 = l1.next
            if l2:
                v2 = l2.val
                l2 = l2.next
            carry, val = divmod(v1 + v2 + carry, 10)
            p.next = ListNode(val)
            p = p.next
        return root.next


def listToLink(l):
    ret = ListNode(0)
    p = ret
    for i in l:
        p.val = i
        p.next = ListNode(0)
        p = p.next

    p = ret
    while p and p.next:
        if p.next.next is None and p.next.val == 0:
            p.next = None
        p = p.next

    return ret


def printList(l):
    while (l):
        print("%d -> " % l.val, end='')
        l = l.next
    print()


l1 = [3, 4, 9]
l2 = [8, 5]
# l1 = [0]
# l2 = [0]
ll1 = listToLink(l1)
ll2 = listToLink(l2)
printList(ll1)
printList(ll2)

s = Solution()
printList(s.addTwoNumbers(ll1, ll2))
