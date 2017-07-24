class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = len(s)
        for i in xrange(len(s)):
            for j in xrange(i + 2, len(s) + 1):
                ss = s[i:j]
                if ss == ss[::-1]:
                    count += 1
        return count

# 130 / 130 test cases passed.
# Status: Accepted
# Runtime: 1075 ms
