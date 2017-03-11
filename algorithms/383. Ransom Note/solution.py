class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        chr_count = {}
        for c in magazine:
            chr_count[c] = chr_count.get(c, 0) + 1
        for c in ransomNote:
            chr_count[c] = chr_count.get(c, 0) - 1
        return len(filter(lambda c: chr_count[c] < 0, chr_count)) == 0

# test
s = Solution().canConstruct
assert False == s("a", "b")
assert False == s("aa", "ab")
assert True == s("aa", "aab")
