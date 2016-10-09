# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
import gc

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        if not headA or not headB:
            return

        cur_a = headA
        la = 1
        while cur_a.next:
            cur_a = cur_a.next
            la += 1

        cur_b = headB
        lb = 1
        while cur_b.next:
            cur_b = cur_b.next
            lb += 1

        if cur_a != cur_b:
            return

        cur_a = headA
        cur_b = headB
        while la > lb:
            la -= 1
            cur_a = cur_a.next
        while lb > la:
            lb -= 1
            cur_b = cur_b.next

        while cur_a != cur_b:
            cur_a = cur_a.next
            cur_b = cur_b.next

        # deal with MLE...
        gc.collect()
        return cur_a
