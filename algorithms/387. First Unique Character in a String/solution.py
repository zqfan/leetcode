class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        letters = [chr(ord('a') + i) for i in xrange(26)]
        # Remember that collections.Counter is 100 times slower than s.count
        positions = [s.find(c) for c in letters if s.count(c) == 1]
        return min(positions) if positions else -1

# 104 / 104 test cases passed.
# Status: Accepted
# Runtime: 85 ms
