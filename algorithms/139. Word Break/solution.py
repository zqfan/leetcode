class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: Set[str]
        :rtype: bool
        """
        w_min = len(s)
        w_max = 0
        for w in wordDict:
            w_min = min(w_min, len(w))
            w_max = max(w_max, len(w))
        dp = [False] * (len(s) + 1)
        dp[0] = True
        for i in range(1, len(s)+1):
            j_min = min(0, i-w_max)
            for j in range(j_min, i-w_min+1):
                dp[i] |= dp[j] and s[j:i] in wordDict
                if dp[i]:
                    break
        return dp[-1]
