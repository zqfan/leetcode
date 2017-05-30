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
        def inorder(count):
            if count == 0:
                return
            root = TreeNode(0)
            root.left = inorder(count / 2)
            root.val = cur[0].val
            cur[0] = cur[0].next
            root.right = inorder(count - count / 2 - 1)
            return root

        cur = head
        count = 0
        while cur:
            count += 1
            cur = cur.next
        cur = [head]
        return inorder(count)

# 32 / 32 test cases passed.
# Status: Accepted
# Runtime: 266 ms
# beats 70.62 %
