class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        words = str.split(' ')
        if len(pattern) != len(words):
            return False
        follow_map = {}
        follow_map_reverse = {}
        for i, c in enumerate(pattern):
            if words[i] != follow_map.setdefault(c, words[i]):
                return False
            if c != follow_map_reverse.setdefault(words[i], c):
                return False
        return True

# test
s = Solution().wordPattern
assert s("abba", "dog cat cat dog") == True
assert s("abba", "dog cat cat fish") == False
assert s("aaaa", "dog cat cat dog") == False
assert s("abba", "dog dog dog dog") == False
