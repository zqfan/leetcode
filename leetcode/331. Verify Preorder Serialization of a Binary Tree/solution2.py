class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        if preorder == '#':
            return True
        node_arr = preorder.split(',')
        stack = []
        trees = 0
        for node in node_arr:
            if node != '#':
                stack.append(2)
            else:
                if not stack:
                    return False
                stack[-1] -= 1
                if stack[-1] < 0:
                    return False
                while stack and stack[-1] == 0:
                    stack.pop()
                    if stack:
                        stack[-1] -= 1
            if not stack:
                trees += 1
        return len(stack) == 0 and trees == 1
