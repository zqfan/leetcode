class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        # refe to https://leetcode.com/discuss/56982/o-sqrt-n-in-ruby-and-c
        while n %  4 == 0:
            n /= 4
        if n % 8 == 7:
            return 4
        i = 0
        while i ** 2 < n:
            j = int(math.sqrt(n - i ** 2))
            if i ** 2 + j ** 2 == n:
                return bool(i) + bool(j)
            i += 1
        return 3
