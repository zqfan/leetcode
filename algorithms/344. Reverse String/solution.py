class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        return ''.join(reversed(s))

# test
s = Solution().reverseString
assert s( "hello") == "olleh"
