class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def get_divisors(n):
            d = [1]; k = 2
            while k * k < n:
                if n % k == 0:
                    d.append(k)
                    d.append(n/k)
                k += 1
            if k * k == n:
                d.append(k)
            return d

        dp = {}; path = {}; maxlen = maxlenidx = 0
        nums.sort()
        for n in nums:
            path[n] = n
            divisors = get_divisors(n)
            for d in divisors:
                if dp.get(d, 0) >= dp.get(n, 0):
                    dp[n] = dp.get(d, 0) + 1
                    if dp.get(d):
                        path[n] = d
                    if dp[n] > maxlen:
                        maxlen = dp[n]
                        maxlenidx = n
        res = []
        while maxlen:
            res.append(maxlenidx)
            maxlenidx = path[maxlenidx]
            maxlen -= 1
        return res
