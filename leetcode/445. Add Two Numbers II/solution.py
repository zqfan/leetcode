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
        def get_number(l):
            n = 0
            while l:
                n = n * 10 + l.val
                l = l.next
            return n
        total = get_number(l1) + get_number(l2)
        head = ListNode(total % 10)
        while total / 10:
            tmp = head
            total /= 10
            head = ListNode(total % 10)
            head.next = tmp
        return head

# 1563 / 1563 test cases passed.
# Status: Accepted
# Runtime: 119 ms
# 96.66%
