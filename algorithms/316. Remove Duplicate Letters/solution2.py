class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        # @lixx2100
        count = [0] * 26
        for c in s:
            count[ord(c)-ord('a')] += 1
        def helper(remains):
            if not remains:
                return ''
            minpos = 0
            for i, c in enumerate(s):
                if c < s[minpos]:
                    minpos = i
                count[ord(c)-ord('a')] -= 1
                if count[ord(c)-ord('a')] == 0:
                    break
            remains = s[minpos+1:].replace(s[minpos], '')
            count[ord(s[minpos])-ord('a')] = 0
            return s[minpos] + self.removeDuplicateLetters(remains)
        return helper(s)

# 286 / 286 test cases passed.
# Status: Accepted
# Runtime: 225 ms
# 7.93%
