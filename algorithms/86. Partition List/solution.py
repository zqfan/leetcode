# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        lt = lttail = ListNode(0)
        ge = getail = ListNode(0)
        while head:
            if head.val < x:
                lttail.next = lttail = head
                #lttail = head
            else:
                getail.next = getail = head
                #getail = head
            head = head.next
        lttail.next = ge.next
        getail.next = None
        return lt.next
