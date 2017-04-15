class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 2:
            return 0
        isPrime = [1] * n
        for i in xrange(2, int(n ** 0.5) + 1):
            if isPrime[i]:
                for j in xrange(i * i, n, i):
                    isPrime[j] = 0
        return sum(isPrime) - 2

# 20 / 20 test cases passed.
# Status: Accepted
# Runtime: 795 ms
# beats 72.09%
