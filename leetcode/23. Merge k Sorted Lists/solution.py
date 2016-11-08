# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        # O(N*logK): each element need push into and pop from heap
        heap = []
        for node in lists:
            if node:
                heapq.heappush(heap, (node.val, node))
        if len(heap) == 0:
            return
        head = cur = heapq.heappop(heap)[1]
        if head.next:
            heapq.heappush(heap, (head.next.val, head.next))
        while heap:
            node = heapq.heappop(heap)[1]
            cur.next = node
            cur = node
            if node.next:
                heapq.heappush(heap, (node.next.val, node.next))
        return head
