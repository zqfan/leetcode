class Solution(object):
    def strangePrinter(self, s):
        """
        :type s: str
        :rtype: int
        """
        def dfs(i, j):
            if i >= j:
                return 0 if i > j else 1
            if (i, j) not in mem:
                mem[i, j] = dfs(i+1, j) + 1
                for k in xrange(i+1, j+1):
                    if s[i] == s[k]:
                        mem[i, j] = min(mem[i, j], dfs(i, k-1) + dfs(k+1, j))
            return mem[i, j]
        mem = {}
        return dfs(0, len(s) - 1)

# 201 / 201 test cases passed.
# Status: Accepted
# Runtime: 1425 ms
