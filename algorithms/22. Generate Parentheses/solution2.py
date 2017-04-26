class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        def dfs(n):
            if n in mem:
                return mem[n]
            s = set('(' + p + ')' for p in dfs(n - 1))
            for i in xrange(1, n / 2 + 1):
                for p1 in dfs(i):
                    for p2 in dfs(n - i):
                        s.add(p1 + p2)
                        s.add(p2 + p1)
            return mem.setdefault(n, list(s))
        mem = {1 : ['()']}
        return dfs(n) if n > 0 else []

# 8 / 8 test cases passed.
# Status: Accepted
# Runtime: 52 ms
# beats 65.63 %
