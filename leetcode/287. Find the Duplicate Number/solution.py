class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # @echoxiaolee
        slow = nums[0]
        fast = nums[nums[0]]
        while fast != slow:
            slow = nums[slow]
            fast = nums[nums[fast]]
        slow = 0
        while fast != slow:
            slow = nums[slow]
            fast = nums[fast]
        return slow

# 53 / 53 test cases passed.
# Status: Accepted
# Runtime: 35 ms
# 98.75%
