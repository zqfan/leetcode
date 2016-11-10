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
        cur_ptr = head
        length = 0
        while cur_ptr:
            cur_ptr = cur_ptr.next
            length += 1
        nodes = [[None]*((length+1)/2), [None]*(length/2)]
        cur_ptr = head
        for i in range(len(nodes[0])):
            nodes[0][i] = cur_ptr
            cur_ptr = cur_ptr.next
        for i in range(len(nodes[1])):
            nodes[1][i] = cur_ptr
            cur_ptr = cur_ptr.next
        cur_ptr = head
        index = 1
        while index < length:
            if index % 2 == 0:
                cur_ptr.next = nodes[0][index/2]
            else:
                cur_ptr.next = nodes[1][-(index+1)/2]
            cur_ptr = cur_ptr.next
            index += 1
        cur_ptr.next = None
