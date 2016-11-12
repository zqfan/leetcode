# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return
        odd = head
        even = dummy = head.next
        while even and even.next:
            odd.next = odd = even.next
            even.next = even = odd.next
        odd.next = dummy
        return head
