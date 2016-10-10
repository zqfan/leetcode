class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        col_title = ""
        while n:
            n -= 1
            c = chr(n % 26 + ord('A'))
            col_title = c + col_title
            n /= 26
        return col_title
