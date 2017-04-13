class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        words = str.split()
        p, w = {}, {}
        i = 0
        while i < len(pattern):
            if i >= len(words) or p.get(pattern[i], 0) != w.get(words[i], 0):
                return False
            p[pattern[i]] = w[words[i]] = i + 1
            i += 1
        return i == len(words)
