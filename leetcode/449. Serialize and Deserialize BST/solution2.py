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
        node_str_arr = []
        queue = collections.deque()
        queue.append(root)
        while queue:
            cur = queue.popleft()
            if not cur:
                node_str_arr.append('')
            else:
                node_str_arr.append(str(cur.val))
                queue.append(cur.left)
                queue.append(cur.right)
        while node_str_arr and node_str_arr[-1] == '':
            node_str_arr.pop()
        return ','.join(node_str_arr)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if not data:
            return
        node_str_arr = data.split(',')
        root = TreeNode(int(node_str_arr[0]))
        queue = collections.deque()
        queue.append(root)
        idx = 1
        while queue:
            cur = queue.popleft()
            if idx < len(node_str_arr) and node_str_arr[idx] != '':
                cur.left = TreeNode(int(node_str_arr[idx]))
                queue.append(cur.left)
            idx += 1
            if idx < len(node_str_arr) and node_str_arr[idx] != '':
                cur.right = TreeNode(int(node_str_arr[idx]))
                queue.append(cur.right)
            idx += 1
        return root

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))

# 62 / 62 test cases passed.
# Status: Accepted
# Runtime: 119 ms
# 89.87%
