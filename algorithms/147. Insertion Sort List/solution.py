# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return
        dummy = ListNode(None)
        cur = dummy.next = head
        while cur.next:
            if cur.next.val < cur.val:
                p = dummy
                while p.next.val < cur.next.val:
                    p = p.next
                t = cur.next
                cur.next = t.next
                t.next = p.next
                p.next = t
            else:
                cur = cur.next
        return dummy.next
