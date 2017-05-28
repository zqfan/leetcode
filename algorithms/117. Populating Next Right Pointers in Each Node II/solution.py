# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        tail = dummy = TreeLinkNode(0)
        while root:
            tail.next = root.left
            tail = tail.next or tail
            tail.next = root.right
            tail = tail.next or tail
            root = root.next
            if not root:
                root = dummy.next
                tail = dummy
