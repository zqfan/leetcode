class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if not nums:
            return False
        num_sum = sum(nums)
        if num_sum % 2 == 1:
            return False
        dp = [0] * (num_sum/2 + 1)
        dp[0] = 1
        cur_sum = 0
        for n in nums:
            end = min(num_sum/2, cur_sum)
            for j in reversed(range(end+1)):
                if dp[j] and j+n <= num_sum/2:
                    dp[j+n] += 1
            cur_sum += n
        return dp[num_sum/2] > 1
