class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        low, high = 0, len(nums) - 1
        while low < high:
            mid = (low + high) / 2
            if nums[mid] > nums[high]:
                low = mid + 1
            else:
                high = mid
        rot = low
        print rot
        low, high = 0, len(nums) - 1
        while low <= high:
            mid = (low + high) / 2
            rotmid = (mid + rot) % len(nums)
            if nums[rotmid] > target:
                high = mid - 1
            elif nums[rotmid] < target:
                low = mid + 1
            else:
                return rotmid
        return -1
