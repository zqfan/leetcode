mem = {1 : 0}
class Solution(object):
    def minSteps(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n in mem:
            return mem[n]
        s = n
        for i in xrange(2, int(n ** 0.5) + 1):
            if n % i == 0:
                s = i + self.minSteps(n / i)
                break
        return mem.setdefault(n, s)

# 126 / 126 test cases passed.
# Status: Accepted
# Runtime: 36 ms
# beats 84.23 %
