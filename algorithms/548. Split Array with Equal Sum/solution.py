class Solution(object):
    def splitArray(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        sums = [0] * (n + 1)
        for i in xrange(n):
            sums[i + 1] = sums[i] + nums[i]
        for j in xrange(3, n - 3):
            s = set()
            for i in xrange(1, j - 1):
                if sums[i] == (sums[j] - sums[i+1]):
                    s.add(sums[i])
            for k in xrange(j + 2, n - 1):
                sjk = sums[k] - sums[j+1]
                skn = sums[n] - sums[k+1]
                if sjk == skn and sjk in s:
                    return True
        return False
