class Solution(object):
    def splitLoopedString(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        result = ""
        maxstrs = [max(s, s[::-1]) for s in strs]
        for i, word in enumerate(strs):
            mid = ''.join(maxstrs[i+1:] + maxstrs[:i])
            for j in xrange(len(word)):
                result = max(result, word[j:] + mid + word[:j])
            rword = word[::-1]
            for j in xrange(len(rword)):
                result = max(result, rword[j:] + mid + rword[:j])
        return result

# 49 / 49 test cases passed.
# Status: Accepted
# Runtime: 232 ms
