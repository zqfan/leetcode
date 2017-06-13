class Solution(object):
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = 0
        while n > 1:
            if n & 1 == 0:
                n /= 2
            elif n % 4 == 1 or n == 3:
                n -= 1
            else:
                n += 1
            count += 1
        return count
