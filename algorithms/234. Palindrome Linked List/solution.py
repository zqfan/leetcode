# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        fast, reverse = head, None
        while fast and fast.next:
            fast = fast.next.next
            reverse, reverse.next, head = head, reverse, head.next
        fast = head.next if fast else head
        p = True
        while reverse:
            p = p and reverse.val == fast.val
            fast = fast.next
            head, head.next, reverse = reverse, head, reverse.next
        return p
