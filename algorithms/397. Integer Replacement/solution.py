class Solution(object):
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 2:
            return 0
        step = 0
        while n > 3:
            if n % 2 == 0:
                n = n / 2
            else:
                if (n + 1) % 4 == 0:
                    n += 1
                else:
                    n -= 1
            step += 1
        return step + (n - 1)


# test
s = Solution().integerReplacement
assert 3 == s(8)
assert 4 == s(7)
assert 31 == s(100000000)
