class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        for i in xrange(len(nums)-1):
            if nums[i] == nums[i+1] == 0:
                return True
        if k == 0:
            return False  # seriously why? I think it should be true
        k = abs(k)
        d = {0: -1}
        m = 0
        for i, n in enumerate(nums):
            m = (n + m) % k
            if i - d.setdefault(m, i) > 1:
                return True
        return False
