class Solution(object):
    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        def dfs(node):
            visited.add(node)
            for friend in xrange(len(M)):
                if M[node][friend] and friend not in visited:
                    dfs(friend)

        circle = 0
        visited = set()
        for node in xrange(len(M)):
            if node not in visited:
                dfs(node)
                circle += 1
        return circle
