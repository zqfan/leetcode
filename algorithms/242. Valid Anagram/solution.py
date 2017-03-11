# -*- coding: utf-8 -*-
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False

        chr_count = {}
        for c in s:
            chr_count[c] = chr_count.get(c, 0) + 1
        for c in t:
            chr_count[c] = chr_count.get(c, 0) - 1
            if chr_count[c] < 0:
                return False
        return True

    def isAnagramUnicode(self, s, t):
        # unicode is a very large set, we should not use word count in case s
        # is large
        if len(s) != len(t):
            return False
        sorted_s = sorted(s)
        sorted_t = sorted(t)
        for i in range(len(s)):
            if sorted_s[i] != sorted_t[i]:
                return False
        return True

# test
s = Solution().isAnagram
assert True == s("anagram", "nagaram")
assert False == s("rat", "car")
s = Solution().isAnagramUnicode
assert False == s(u"爱情", u"暧昧")
assert True == s(u"爱情", u"情爱")
