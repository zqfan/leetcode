class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return sum(nums)
        maxp = nums[0]
        pp = np = 0  # positive product and negative product
        for n in nums:
            if n > 0:
                pp, np = pp * n or n, np * n
            elif n < 0:
                pp, np = np * n, pp * n or n
            else:
                pp = np = 0
            maxp = max(maxp, pp)
        return maxp
