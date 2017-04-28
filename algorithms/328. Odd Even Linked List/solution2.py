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
        oddhead, evenhead = ListNode(0), ListNode(0)
        oddcur, evencur, cur, count = oddhead, evenhead, head, 1
        while cur:
            if count & 1:
                oddcur.next = cur
                oddcur = cur
            else:
                evencur.next = cur
                evencur = cur
            cur = cur.next
            count += 1
        oddcur.next = evenhead.next
        evencur.next = None
        return oddhead.next
