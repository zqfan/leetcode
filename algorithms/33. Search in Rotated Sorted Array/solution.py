class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        low, high = 0, len(nums) - 1
        while low <= high:
            mid = (low + high) / 2
            # nums = 4 5 6 7 0 1 2, target = 6
            # turn nums to 4 5 6 7 inf inf inf
            # if target = 1
            # turn nums to -inf -inf -inf -inf 0 1 2
            if (nums[mid] < nums[0]) == (target < nums[0]):
                midval = nums[mid]
            else:
                midval = [float('inf'), float('-inf')][target < nums[0]]
            if midval < target:
                low = mid + 1
            elif midval > target:
                high = mid - 1
            else:
                return mid
        return -1

# 196 / 196 test cases passed.
# Status: Accepted
# Runtime: 43 ms
# beats 77.81 %
