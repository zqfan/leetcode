class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_table = [0] * 3
        for i in range(len(nums)-1, -1, -1):
            max_table[0] = max(nums[i] + max_table[2], max_table[1])
            max_table[2] = max_table[1]
            max_table[1] = max_table[0]
        return max_table[0]
