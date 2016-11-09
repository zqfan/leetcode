class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: Set[str]
        :rtype: bool
        """
        f = [[0]*len(s) for i in range(len(s))]
        for i in range(len(s)-1, -1, -1):
            for j in range(i, len(s)):
                ss = s[i:j+1]
                if ss in wordDict:
                    f[i][j] = 1
                for k in range(i, j):
                    f[i][j] += f[i][k] * f[k+1][j]
        return bool(f[0][-1])
