class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        r, n = 0, x
        while n > 0:
            r = r * 10 + n % 10
            n /= 10
        return x == r
