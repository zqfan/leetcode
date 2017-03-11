# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        l1 = l2 = head
        while l2.next and l2.next.next:
            l2 = l2.next.next
            l1 = l1.next
        l2 = l1.next
        l1.next = None
        l1 = self.sortList(head)
        l2 = self.sortList(l2)
        p = dummy = ListNode(0)
        while l1 and l2:
            if l1.val < l2.val:
                p.next = l1
                l1 = l1.next
            else:
                p.next = l2
                l2 = l2.next
            p = p.next
        p.next = l1 if l1 else l2
        return dummy.next
