class Solution(object):
    def maxNumberOfBalloons(self, text):
        """
        :type text: str
        :rtype: int
        """
        return min(text.count(c) // "balloon".count(c) for c in "balloon")
