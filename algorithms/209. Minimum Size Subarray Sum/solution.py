class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        left = total = 0
        minlen = float('inf')
        for right in xrange(len(nums)):
            total += nums[right]
            while total >= s + nums[left]:
                total -= nums[left]
                left += 1
            if total >= s:
                minlen = min(minlen, right - left + 1)
        return minlen if minlen != float('inf') else 0
