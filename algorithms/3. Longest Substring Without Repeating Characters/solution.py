class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        result, start, lastPos = 0, -1, {}
        for i, c in enumerate(s):
            if start < lastPos.get(c, -1):
                start = lastPos.get(c, -1)
            lastPos[c] = i
            result = max(result, i - start)
        return result
