class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        ugly = [float('inf')] * n
        ugly[0] = 1
        idx = [0, 0, 0]
        primes = [2, 3, 5]
        for i in xrange(1, n):
            for j, p in enumerate(primes):
                if p * ugly[idx[j]] <= ugly[i-1]:
                    idx[j] += 1
                ugly[i] = min(ugly[i], p * ugly[idx[j]])
        return ugly[-1]
