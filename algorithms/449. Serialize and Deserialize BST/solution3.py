# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        def helper(cur):
            if not cur:
                node_str_arr.append('')
                return
            node_str_arr.append(str(cur.val))
            helper(cur.left)
            helper(cur.right)

        node_str_arr = []
        helper(root)
        while node_str_arr and node_str_arr[-1] == '':
            node_str_arr.pop()
        return ','.join(node_str_arr)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        def helper(idx):
            if idx >= len(node_str_arr) or node_str_arr[idx] == '':
                return None, idx
            root = TreeNode(int(node_str_arr[idx]))
            root.left, idx = helper(idx+1)
            root.right, idx = helper(idx+1)
            return root, idx

        node_str_arr = data.split(',')
        return helper(0)[0]

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))

# 62 / 62 test cases passed.
# Status: Accepted
# Runtime: 142 ms
# 60.80%
