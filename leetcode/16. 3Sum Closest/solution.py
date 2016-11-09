class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        closest = nums[0] + nums[1] + nums[2]
        delta = abs(target - closest)
        for i in range(len(nums)-2):
            j = i + 1
            k = len(nums) - 1
            while j < k:
                s = nums[i] + nums[j] + nums[k]
                if s < target:
                    j += 1
                    if target - s < delta:
                        closest = s
                        delta = target - s
                elif s > target:
                    k -= 1
                    if s - target < delta:
                        closest = s
                        delta = s - target
                else:
                    return s
        return closest
