class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        # @StefanPochmann
        words = str.split()
        return map(pattern.find, pattern) == map(words.index, words)
