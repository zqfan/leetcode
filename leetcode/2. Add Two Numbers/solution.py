# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        head = cur = ListNode(0)
        while l1 or l2 or carry:
            s = (l1 and l1.val or 0) + (l2 and l2.val or 0) + carry
            carry = s / 10
            cur.next = ListNode(s % 10)
            cur = cur.next
            l1 = l1 and l1.next
            l2 = l2 and l2.next
        return head.next
