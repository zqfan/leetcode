class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        min_len = len(nums) + 1
        cur_sum = 0
        i = j = 0
        while i <= j < len(nums):
            while j < len(nums) and cur_sum + nums[j] < s:
                cur_sum += nums[j]
                j += 1
            if j < len(nums):
                cur_sum += nums[j]
                j += 1
            while i < len(nums) and cur_sum >= s:
                cur_sum -= nums[i]
                i += 1
            min_len = min(min_len, j-i+1)
        return min_len if min_len <= len(nums) else 0
