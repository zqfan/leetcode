class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        c_count = dict((chr(ord('a') + x), 0) for x in range(26))
        for c in s:
            c_count[c] += 1
        for c in t:
            c_count[c] -= 1
        return filter(lambda x: c_count[x], c_count)[0]


# test
s = Solution().findTheDifference
assert 'e' == s('abcd', 'abcde')
