class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        third_num = None
        max3set = set()
        for i, n in enumerate(nums):
            if n not in max3set:
                max3set.add(n)
                third_num = min(max3set)
            if len(max3set) >= 3:
                break
        else:
            return max(max3set)

        for j in range(i, len(nums)):
            if nums[j] not in max3set and nums[j] > third_num:
                max3set.remove(third_num)
                max3set.add(nums[j])
                third_num = min(max3set)

        return third_num


# test
s = Solution().thirdMax
assert s([3,2,1]) == 1
assert s([1,2]) == 2
assert s([2,2,3,1]) == 1
assert s([1,2,3,4,5,6,7,8,9]) == 7
