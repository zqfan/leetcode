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
        ordered_tail = head
        while ordered_tail and ordered_tail.next:
            if ordered_tail.next.val <= head.val:
                onn = ordered_tail.next.next
                ordered_tail.next.next = head
                head = ordered_tail.next
                ordered_tail.next = onn
                continue
            cursor = head
            while ordered_tail.next.val > cursor.next.val:
                cursor = cursor.next
            if cursor != ordered_tail:
                cn = cursor.next
                onn = ordered_tail.next.next
                cursor.next = ordered_tail.next
                ordered_tail.next.next = cn
                ordered_tail.next = onn
            else:
                ordered_tail = ordered_tail.next
        return head
