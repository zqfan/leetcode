class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        l = 0
        counter = collections.defaultdict(int)
        for c in s:
            if counter[c]:
                l += 2
                counter[c] = 0
            else:
                counter[c] = 1
        return l + (sum(counter.itervalues()) > 0)

# 95 / 95 test cases passed.
# Status: Accepted
# Runtime: 45 ms
