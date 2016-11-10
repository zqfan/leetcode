# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        if not head:
            return
        # find left part tail, using two runners
        fast = slow = head
        while 1:
            fast = fast.next
            if not fast:
                break
            fast = fast.next
            if not fast:
                break
            slow = slow.next
        # reverse right part
        # note we eventually get left and right part have same tail
        cur = slow
        pre = slow.next
        slow.next = None
        while pre:
            t = pre.next
            pre.next = cur
            cur = pre
            pre = t
        # merge two list
        l = head
        r = cur
        # becareful, we have a same tail node in two list
        while l and r and l != r:
            t = r.next
            r.next = l.next
            l.next = r
            l = r.next
            r = t
