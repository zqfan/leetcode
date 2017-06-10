# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        start = dummy = ListNode(0)
        cur = dummy.next = head
        for i in xrange(1, m):
            cur = cur.next
            start = start.next
        pre = cur
        cur = cur.next
        for i in xrange(m, n):
            next = cur.next
            cur.next = pre
            pre = cur
            cur = next
        start.next.next = cur
        start.next = pre
        return dummy.next

# 44 / 44 test cases passed.
# Status: Accepted
# Runtime: 35 ms
# beats 97.75 %
