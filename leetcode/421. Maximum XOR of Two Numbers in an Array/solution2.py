class Solution(object):
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        class Node():
            def __init__(self):
                self.left = None
                self.right = None

        root = Node()
        max_xor = 0
        for n in nums:
            cur = cmp = root
            xor = 0
            for i in range(31, -1, -1):
                if not (n & (1<<i)):
                    if not cur.left:
                        cur.left = Node()
                    if cmp and cmp.right:
                        xor |= 1<<i
                        cmp = cmp.right
                    elif cmp:
                        cmp = cmp.left
                    cur = cur.left
                if n & (1<<i):
                    if not cur.right:
                        cur.right = Node()
                    if cmp and cmp.left:
                        xor |= 1<<i
                        cmp = cmp.left
                    elif cmp:
                        cmp = cmp.right
                    cur = cur.right
            max_xor = max(max_xor, xor)
        return max_xor
