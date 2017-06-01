# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        # @StefanPochmann
        def rm(node):
            if not node:
                return 0, None
            i, node.next = rm(node.next)
            return i+1, [node, node.next][i+1 == n]
        return rm(head)[1]
