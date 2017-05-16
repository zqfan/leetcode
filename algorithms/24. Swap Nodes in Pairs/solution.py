# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        cur = dummy = ListNode(0)
        dummy.next = head
        while cur and cur.next and cur.next.next:
            cur.next.next.next, cur.next.next, cur.next = cur.next, cur.next.next.next, cur.next.next
            cur = cur.next.next
        return dummy.next
