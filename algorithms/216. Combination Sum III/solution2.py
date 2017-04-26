class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        def dfs(s, n):
            if len(path) >= k:
                if n == 0:
                    result.append(path[:])
                return
            for i in xrange(s, 10):
                if n < i:
                    return
                path.append(i)
                dfs(i + 1, n - i)
                path.pop()
        result, path = [], []
        dfs(1, n)
        return result
