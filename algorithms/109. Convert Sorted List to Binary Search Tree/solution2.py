# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        if not head:
            return
        slow = fast = head
        pre = None
        while fast and fast.next:
            pre = slow
            slow = slow.next
            fast = fast.next.next
        root = TreeNode(slow.val)
        root.right = self.sortedListToBST(slow.next)
        if pre:
            pre.next = None
            root.left = self.sortedListToBST(head)
            pre.next = slow
        return root

# 32 / 32 test cases passed.
# Status: Accepted
# Runtime: 359 ms
# beats 7.65 %
