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
