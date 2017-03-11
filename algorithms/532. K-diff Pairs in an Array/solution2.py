class Solution(object):
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        res = 0
        nums.sort()
        for i in xrange(len(nums)):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            l = i + 1
            r = len(nums) - 1
            while l <= r:
                m = (l + r) / 2
                d = nums[m] - nums[i]
                if d < k:
                    l = m + 1
                elif d > k:
                    r = m - 1
                else:
                    res += 1
                    break
        return res
