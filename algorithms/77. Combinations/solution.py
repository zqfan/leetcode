class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        def dfs(start, path):
            if len(path) == k:
                result.append(path[:])
                return
            for i in xrange(start, n + 1):
                path.append(i)
                dfs(i + 1, path)
                path.pop();
        result = []
        dfs(1, [])
        return result
