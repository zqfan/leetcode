class Solution(object):
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        m = 0
        for i in xrange(1, len(nums)):
            if nums[i] < nums[i-1]:
                if m:
                    return False
                m = 1
                if i == 1 or nums[i-2] <= nums[i]:
                    nums[i-1] = nums[i]
                else:
                    nums[i] = nums[i-1]
        return True

# 325 / 325 test cases passed.
# Status: Accepted
# Runtime: 56 ms
