class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        counter = collections.Counter(s)
        for i, c in enumerate(s):
            if counter[c] == 1:
                return i
        return -1

# 104 / 104 test cases passed.
# Status: Accepted
# Runtime: 365 ms
