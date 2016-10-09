# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        while head and head.val == val:
            t = head
            head = head.next
            t.next = None
        if not head:
            return
        cur = head
        while cur.next:
            if cur.next.val != val:
                cur = cur.next
                continue
            t = cur.next
            cur.next = cur.next.next
            t.next = None
        return head
