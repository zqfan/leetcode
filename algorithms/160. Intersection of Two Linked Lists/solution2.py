# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        la, cur = 0, headA
        while cur:
            la += 1
            cur = cur.next
        lb, cur = 0, headB
        while cur:
            lb += 1
            cur = cur.next
        while la > lb:
            headA = headA.next
            la -= 1
        while lb > la:
            headB = headB.next
            lb -= 1
        while headA != headB:
            headA = headA.next
            headB = headB.next
        return headA
