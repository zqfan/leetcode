class Solution(object):
    def findLongestWord(self, s, d):
        """
        :type s: str
        :type d: List[str]
        :rtype: str
        """
        # @StefanPochmann
        def issubseq(string):
            it = iter(s)
            return all(char in it for char in string)
        return min(filter(issubseq, d)+[''], key=lambda x: (-len(x), x))
