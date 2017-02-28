class Solution(object):
    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """
        def helper(start, end):
            if start > end:
                return 0
            if mem[start][end]:
                return mem[start][end]
            if s[start] != s[end]:
                mem[start][end] = max(helper(start, end-1), helper(start+1, end))
            elif start != end:
                mem[start][end] = helper(start+1, end-1) + 2
            else:
                mem[start][end] = 1
            return mem[start][end]

        mem = [[0] * len(s) for _ in xrange(len(s))]
        return helper(0, len(s)-1)
