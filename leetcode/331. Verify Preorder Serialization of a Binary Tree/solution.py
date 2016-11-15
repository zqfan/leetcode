class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        node_arr = preorder.split(',')
        if node_arr[0] == '#':
            return len(node_arr) == 1
        children = 1; trees = 0
        for node in node_arr:
            if children > 0:
                if node == '#':
                    children -= 1
                else:
                    children += 1
            elif children < 0:
                return False
            else:
                trees += 1
        return children == 0 and trees < 1
