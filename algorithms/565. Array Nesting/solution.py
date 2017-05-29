class Solution(object):
    def arrayNesting(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        v = [0] * len(nums)
        maxi = cur = 0
        for i in xrange(len(nums)):
            if not v[i]:
                cur = 0
                while not v[i]:
                    v[i] = 1
                    i = nums[i]
                    cur += 1
                maxi = max(maxi, cur)
        return maxi
