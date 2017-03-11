class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        equal = 0
        i = 0
        j = len(nums) - 1
        while i < j:
            if nums[i] != nums[j]:
                if equal > 0:
                    equal -= 1
                else:
                    j -= 1
            else:
                equal += 1
            i += 1
        return nums[j]
